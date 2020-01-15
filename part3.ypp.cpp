%{
#include <stdlib.h>
#include <stdio.h>
#include "part3_helpers.hpp"

extern int yylex();
extern char* yytext;
extern int yylineno;

void yyerror(const char*);
void semanticError(string msg);

%}

/* token and precedence definitions */
%token int_tok float_tok void_tok
%token return_tok
%token volatile_tok
%token write_tok read_tok
%token id_tok
%token num_tok
%token str_tok
%right while_tok do_tok if_tok then_tok else_tok
%right assign_tok
%left or_tok
%left and_tok
%left relop_tok
%left addop_tok
%left mulop_tok
%right not_tok
%left '(' '{'
%left ')' '}'
%left '?' ',' ':' ';' '&' '@'

%%

/* define the dictation of cmm */
PROGRAM:        FDEFS {
                        }
;
/* representation of function definitions */
FDEFS:
                FDEFS FUNC_API BLK{
                                    $$ = makeNode("FDEFS", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }

            |
                FDEFS FUNC_API ';' {
                                    $$ = makeNode("FDEFS", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
            |
               /* epsilon */       { $$ = makeNode("FDEFS", NULL, makeNode("EPSILON", NULL, NULL)); }
;

// a single function declaration
FUNC_API:
                TYPE id_tok '(' FUNC_ARGS ')' {
                                                $$ = makeNode("FUNC_API", NULL, $1);
                                                concatList($1, $2);
                                                concatList($1, $3);
                                                concatList($1, $4);
                                                concatList($1, $5);
                                                }
;

// function arguments (0 or more)
FUNC_ARGS:
                FUNC_ARGLIST { $$ = makeNode("FUNC_ARGS", NULL, $1); }
            |
               /* epsilon */       { $$ = makeNode("FUNC_ARGS", NULL, makeNode("EPSILON", NULL, NULL)); }
;

FUNC_ARGLIST:
                FUNC_ARGLIST ',' DCL {
                                    $$ = makeNode("FUNC_ARGLIST", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
            |
                DCL { $$ = makeNode("FUNC_ARGLIST", NULL, $1); }
;

// represents a statements block
BLK:            '{' {symTable.enterBlock();} STLIST {symTable.leaveBlock();}'}' {
                    $$.nextList = $2.nextList; //TODO: is this $2?
                }
;

// variable declaration
DCL:            id_tok ':' TYPE {
                    // make sure type is not void
                    if ($3.type == cmm_void) {
                        semanticError("Cannot declare void variable");
                    }
                    // all definitions will be handled by STMT or the function
                    $$.type = $3.type;
                    $$.argDefinitions.push_back($1.name);
                }
            |
                id_tok ',' DCL {
                    $$.type = $3.type;
                    $$.argDefinitions.push_back($1.name);
                }
;

// variable type
TYPE:
                int_tok {
                    $$.type = cmm_int;
                }
            |
                float_tok {
                    $$.type = cmm_float;
                }
            |
                void_tok {
                    $$.type = cmm_void;
                }
            |
                int_tok'@' {
                    $$.type = cmm_pint;
                }
            |
                volatile_tok int_tok {
                    $$.type = cmm_volatile;
                }
// statement list
STLIST:
                STLIST M STMT {
                    $$.nextList = $3.nextList;
                    codeBuf.backPatch($1.nextList, $2.quad);
                }
            |
               /* epsilon */  {
               }
;

// from here we start defining various statement types
STMT:
                DCL ';' {
                    // go over all declarations, and allocate space for them
                    for (int i=0; i<$1.argDefinitions.size(); ++i) {
                        Symbol newVar(currentStackOffset, $1.type);
                        bool success = symTable.putVar($1.argDefinitions[i], newVar);
                        // check if the id was already declared in this block
                        if (!success) {
                            semanticError("Duplicate variable declaration in the same block");
                        }
                        currentStackOffset += 4;
                    }
                    
                    // all variables were successfully added, update stack pointer
                    codeBuf.emit("ADD2I I2 I2 " + intToString(4*$1.argDefinitions.size()));
                }
            |
                ASSN {
                }
            |
                EXP ';' {
                }
            |
                CNTRL {
                    $$.nextList = $1.nextList;
                }
            |
                READ {
                }
            |
                WRITE {
                }
            |
                RETURN {
                }
            |
                BLK {
                    $$.nextList = $1.nextList;
                }
            |
                ASSN_C {
                    $$.nextList = $1.nextList;
                }
;

RETURN:
                return_tok EXP ';'{
                    if (functionReturnType != $2.type) {
                        semanticError("Bad return type");
                    }
                    // save return value to stack (last value before our frame)
                    if (functionReturnType == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF F" + intToString($2.place) + " F" + intToString(nextFreeRegF) + " -4");
                    }
                    else {
                        codeBuf.emit("STORI I" + intToString($2.place) + " I1 -4");
                    }

                    // do function end semantics
                    codeBuf.emit("COPYI I2 I1");
                    codeBuf.emit("RETRN");
                }
            |
                return_tok';'{
                    if (functionReturnType != cmm_void) {
                        semanticError("missing return value in non-void function");
                    }
                    // do function end semantics
                    codeBuf.emit("COPYI I2 I1");
                    codeBuf.emit("RETRN");
                }
;


WRITE:
                write_tok '(' EXP ')' ';'{
                    if ($3.type == cmm_float) {
                        codeBuf.emit("PRNTF F" + $3.place);
                    }
                    else {
                        codeBuf.emit("PRNTI I" + $3.place);
                    }
                }
			|
				write_tok '(' str_tok ')' ';'{
                    string str = $3.name;
                    bool seenBackslash = false;
                    for (int i = 0; i < str.size(); ++i) {
                        if (str[i] == '\\') {
                            seenBackslash = true;
                        }
                        else {
                            if (!seenBackslash) {
                                codeBuf.emit("PRNTC " + str[i]);
                            }
                            else { // TODO: check that all these work
                                // from lex, we know this char must be one of: n, \, "
                                if (str[i] == "n") {
                                    codeBuf.emit("PRNTC \n");
                                }
                                else if (str[i] == "\\") {
                                    codeBuf.emit("PRNTC \\");
                                }
                                else {
                                    codeBuf.emit("PRNTC \"");
                                }
                            }
                        }
                    }
                }
;

READ:
			read_tok '(' LVAL ')' ';'{
				if ($3.type == cmm_float) {
					codeBuf.emit("READF F" + intToString(nextFreeRegF));
					codeBuf.emit("CITOF F" + intToString(nextFreeRegF+1) + " I1");
					codeBuf.emit("STORF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF + 1) + " " + intToString($3.offset));
				}
				else if ($3.type == cmm_int || $3.type == cmm_volatile) {
					codeBuf.emit("READI I" + intToString(nextFreeRegI));
                    if ($3.dereferencedPtr == true) {
                        codeBuf.emit("STORI I" + intToString(nextFreeRegI) + " I" + intToString($3.offsetReg) + " 0");
                    }
                    else {
                        codeBuf.emit("STORI I" + intToString(nextFreeRegI) + " I1" + " " + intToString($3.offset));
                    }
				}
				else {
					// id does not exist
					semanticError("variable can not be written from IO");
				}
			}
;

ASSN:
                LVAL assign_tok EXP ';'{
                    // check if types are compatible
                    string typeChar[] = {"I", "F", "I", "", "I"}; // used to convert the "types" enum to string for easier use
                    string Ltype = typeChar[$1.type];
                    string Rtype = typeChar[$3.type];
                    if (Ltype == "" || Rtype == "") {
                        semanticError("Can't assign void type");
                    }
                    if (Ltype != Rtype || ($1.type == cmm_pint && $3.type != cmm_pint) || ($1.type != cmm_pint && $3.type == cmm_pint)) {
                        semanticError ("Bad assignment, type mismatch");
                    }

                    if ($1.type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF" + " F" + intToString($3.place) + " F" intToString(nextFreeRegF) + " " + intToString($1.offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ($3.type == cmm_volatile) {
                            codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($3.offset));
                            $3.place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ($1.dereferencedPtr == true) {
                            codeBuf.emit("STORI" + " I" + intToString($3.place) + " I" + intToString($1.offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI" + " I" + intToString($3.place) + " I1 " + intToString($1.offset));
                        }
                    }

                }
;

// ternary assignment
ASSN_C:
                LVAL assign_tok BEXP '?' M EXP N ':' M EXP ';' {
                    // check if types are compatible
                    string typeChar[] = {"I", "F", "P", "", "I"}; // used to convert the "types" enum to string for easier use
                    string Ltype = typeChar[$1.type];
                    string Rtype1 = typeChar[$6.type];
                    string Rtype2 = typeChar[$10.type];
                    if (Ltype == "" || Rtype1 == "" || Rtype2 == "") {
                        semanticError("Can't assign void type");
                    }
                    if (Ltype != Rtype1 || Ltype != Rtype2) {
                        semanticError ("Bad assignment, type mismatch");
                    }
                    // change type char from P to I for ease of programming
                    if (Ltype == "P") {
                        Ltype = "I";
                        Rtype1 = "I";
                        Rtype2 = "I";
                    }
                    // patch BEXP lists
                    codeBuf.backPatch($3.trueList, $5.quad);
                    codeBuf.backPatch($3.falseList, $9.quad);

                    // start with assignment of second EXP
                    if ($1.type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF" + " F" + intToString($10.place) + " F" intToString(nextFreeRegF) + " " + intToString($1.offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ($10.type == cmm_volatile) {
                            codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($10.offset));
                            $10.place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ($1.dereferencedPtr == true) {
                            codeBuf.emit("STORI" + " I" + intToString($10.place) + " I" + intToString($1.offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI" + " I" + intToString($10.place) + " I1 " + intToString($1.offset));
                        }
                    }
                    
                    // done assignment, need "goto next"
                    $$.nextlist.push_back(codeBuf.nextQuad());
                    codeBuf.emit("UJUMP ");
                    
                    // done with assignment code for EXP2, we can patch to make EXP1 code jump here
                    codeBuf.backPatch($7.nextlist, codeBuf.nextQuad());

                    // start assignment code for first EXP
                    if ($1.type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF" + " F" + intToString($6.place) + " F" intToString(nextFreeRegF) + " " + intToString($1.offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ($6.type == cmm_volatile) {
                            c1deBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I0 " + intToString($6.offset));
                            $6.place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ($1.dereferencedPtr == true) {
                            cod1Buf.emit("STORI" + " I" + intToString($6.place) + " I" + intToString($1.offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI" + " I" + intToString($6.place) + " I1 " + intToString($1.offset));
                        }
                    }

                    // done assignment of EXP1, TODO: make sure to backpatch ASSN_C nextlist


                }
;

LVAL:
                id_tok{
					Symbol &idSymbol = symTable.getVar($1.name);
					// make sure the id exists
					if (idSymbol.offset == -1) {
						// id does not exist
						semanticError("variable '" + $1.name + "' is not declared");
					}
					$$.type = idSymbol.type;
					$$.offset = idSymbol.offset;
				}
            |
                '@'EXP{
					// make sure the EXP is a pointer
					if ($2.type != cmm_pint) {
						semanticError("Trying to dereference a non-pointer variable");
					}
					codeBuf.emit("COPYI I" + intToString(nextFreeRegI)) + " I" + intToString($2.place));
                    $$.offsetReg = nextFreeRegI;
					++nextFreeRegI;
					$$.type = cmm_volatile;
                    $$.dereferencedPtr = true;
				}
;

// control statements (if-else, while-do)
CNTRL:
                if_tok BEXP then_tok M STMT N else_tok M STMT{
					codeBuf.backPatch($2.trueList, $4.quad);
					codeBuf.backPatch($2.falseList, $8.quad);
					//merge STMT1.nextList, N.nextList and STMT2.nextList into CNTRL.nextList
					codeBuf.merge($5.nextList, $6.nextList, $$.nextList);
					codeBuf.merge($9.nextList, $$.nextList, $$.nextList);
                 }
            |
                if_tok BEXP then_tok M STMT{
					codeBuf.backPatch($2.trueList, $4.quad);
					//merge STMT.nextList and BEXP.falseList into CNTRL.nextList
					codeBuf.merge($5.nextList, $2.falseList, $$.nextList);  
                 }
            |
                while_tok M BEXP do_tok M STMT{
					codeBuf.backPatch($3.trueList, $5.quad);
					codeBuf.backPatch($6.nextList, $2.quad);
					$$.nextList = $3.falseList;
					codeBuf.emit("UJUMP " + intToString($2.quad));
                 }
// boolean expression
BEXP:
                BEXP or_tok M BEXP{
					//if BEXP1 == false go to BEXP2
					codeBuf.backPatch($1.falseList, $3.quad); 
					codeBuf.merge($1.trueList, $4.trueList, $$.trueList);
					$$.falseList = $4.falseList;
                }
            |
                BEXP and_tok M BEXP{
					//if BEXP1 == true go to BEXP2
					codeBuf.backPatch($1.trueList, $3.quad); 
					codeBuf.merge($1.falseList, $4.falseList, $$.falseList);
					$$.trueList = $4.trueList;
                }
            |
                not_tok BEXP{
                    $$.trueList = $2.falseList;
                    $$.falseList = $2.trueList;
                }
            |
                EXP relop_tok EXP{
                    string type = "";
                    if ( $1.type == cmm_volatile && ($3.type == cmm_volatile || $3.type == cmm_int)) {
                        type = "I";
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($1.offset));
                        $1.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    if ( $3.type == cmm_volatile && ($1.type == cmm_volatile || $1.type == cmm_int)) {
                        type = "I";
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($3.offset));
                        $3.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    if ( $1.type == cmm_int && $3.type == cmm_int ) {
                        type = "I";
                    }
                    if ( $1.type == cmm_float && $3.type == cmm_float ) {
                        type = "F";
                    }
                    if (type == "") {
                        semanticError("relop between incompatible types");
                    }

                    // perform the check, and do the jumps
                    if (type == "I") {
                        $$.trueList.push_back(codeBuf.nextquad() + 1);
                        $$.falseList.push_back(codeBuf.nextquad() + 2);
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else {
                        $$.trueList.push_back(codeBuf.nextquad() + 2);
                        $$.falseList.push_back(codeBuf.nextquad() + 3);
                        $$.place = nextFreeRegF;
                        ++nextFreeRegF;
                    }

                    if ($2.name == "==") {
                        codeBuf.emit("SEQU" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ($2.name == "<>") {
                        codeBuf.emit("SNEQ" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ($2.name == "<") {
                        codeBuf.emit("SLET" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ($2.name == "<=") {
                        codeBuf.emit("SGRT" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BREQZ I" + intToString(nextFreeRegI));
                    }
                    else if ($2.name == ">") {
                        codeBuf.emit("SGRT" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ($2.name == ">=") {
                        codeBuf.emit("SLET" + type + " " + type + intToString($$.place) + " " + type + intToString($1.place) + " " + type + intToString($3.place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($$.place));
                        }
                        codeBuf.emit("BREQZ I" + intToString(nextFreeRegI));
                    }

                    codeBuf.emit("UJUMP");

                }
            |
                '(' BEXP ')'{
                    $$.trueList = $2.trueList;
                    $$.falseList = $2.falseList;
                }
// normal expression
EXP:
                EXP addop_tok EXP{
                    // check if add or sub
                    string op;
                    if ($2.name == "+") {
                        op = "ADD2"
                    }
                    else {
                        op = "SUBT";
                    }

                    // check if types are compatible (2 ints/ 2 floats)
                    if ($1.type == cmm_float && $3.type == cmm_float) {
                        codeBuf.emit(op + "F F" + intToString($1.place) + " F" + intToString($1.place) + " F" + intToString($3.place));
                        $$ = $1;
                    }
                    else if ($1.type == cmm_int && $3.type == cmm_int) {
                        codeBuf.emit(op + "I I" + intToString($1.place) + " I" + intToString($1.place) + " I" + intToString($3.place));
                        $$ = $1;
                    }
                    else if ($1.type == cmm_volatile && $3.type == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($1.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString($3.place));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ($1.type == cmm_int && $3.type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($3.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString($1.place));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ($1.type == cmm_volatile && $3.type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($1.offset));
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI + 1) + " I1 " + intToString($3.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI + 1));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else {
                        semanticError("ADDOP between different types");
                    }
                }
            |
                EXP mulop_tok EXP{
                    // check if mult or div
                    string op;
                    if ($2.name == "*") {
                        op = "MULT"
                    }
                    else {
                        op = "DIVD";
                    }

                    // check if types are compatible (2 ints/ 2 floats)
                    if ($1.type == cmm_float && $3.type == cmm_float) {
                        codeBuf.emit(op + "F F" + intToString($1.place) + " F" + intToString($1.place) + " F" + intToString($3.place));
                        $$ = $1;
                    }
                    else if ($1.type == cmm_int && $3.type == cmm_int) {
                        codeBuf.emit(op + "I I" + intToString($1.place) + " I" + intToString($1.place) + " I" + intToString($3.place));
                        $$ = $1;
                    }
                    else if ($1.type == cmm_volatile && $3.type == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($1.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString($3.place));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ($1.type == cmm_int && $3.type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($3.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString($1.place));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ($1.type == cmm_volatile && $3.type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString($1.offset));
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI + 1) + " I1 " + intToString($3.offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI + 1));
                        $$.type = cmm_int;
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else {
                        semanticError("MULOP between different types");
                    }
                }
            |
                '(' EXP ')'{
                    $$ = $1;
                }
            |
                '(' TYPE ')' EXP {
                    $$ = $4;
                    if ( $2.type != $4.type ) {
                        // TODO: is there casting to void?
                        if ( $2.type == cmm_int && $4.type == cmm_float ) {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString($4.place));
                            $$.place = nextFreeRegI;
                            ++nextFreeRegI;
                            $$.type = cmm_int;
                        }

                        else if ( $2.type == cmm_float && $4.type == cmm_int ) {
                            codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I" + intToString($4.place));
                            $$.place = nextFreeRegF;
                            ++nextFreeRegF;
                            $$.type = cmm_float;
                        }
                        else {
                            // TODO: are there other casting options needed?
                            semanticError("Cast unsupported");
                        }
                    }
                }
            |
                id_tok {
                    Symbol &idSymbol = symTable.getVar($1.name);
                    // make sure the id exists
                    if (idSymbol.offset == -1) {
                        // id does not exist
                        semanticError("variable '" + $1.name + "' is not declared");
                    }
                    $$.type = idSymbol.type;
                    $$.offset = idSymbol.offset;
                    if ($$.type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("LOADF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF) + " " intToString(idSymbol.offset));
                        $$.place = nextFreeRegF;
                        ++nextFreeRegF;
                    }
                    else { // int/volatile/pint
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString(idSymbol.offset));
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }

                }
            |
                '&'EXP {
                    // make sure EXP is a volatile int
                    if ($2.type != cmm_volatile) {
                        semanticError("Trying to reference a non-volatile variable");
                    }
                    codeBuf.emit("ADD2I I" + intToString(nextFreeRegI) + " I1 " + intToString($2.offset));
                    $$.place = nextFreeRegI;
                    ++nextFreeRegI;
                    $$.type = cmm_pint;
                }
        |
                '@'EXP{
                    // make sure the EXP is a pointer
                    if ( $2.type != cmm_pint ) {
                        semanticError("Trying to dereference a non-pointer variable");
                    }
                    codeBuf.emit("LOADI I" + intToString(nextFreeRegI)) + " 0 I" + intToString($2.place) );
                    $$.place = nextFreeRegI;
                    ++nextFreeRegI;
                    $$.type = cmm_int;
                    }
            |
                num_tok {
                    $$.name = $1.name;
                    if ( $$.name.find('.') != std::string::npos ) {
                        // the number is a floating point
                        // TODO: are numbers with E defined or not? fix lex file
                        codeBuf.emit("COPYF F" + intToString(nextFreeRegF) + " " + $$.name);
                        $$.place = nextFreeRegF;
                        $$.type = cmm_float;
                        ++nextFreeRegF;
                    } 
                    else {
                        // the number is a normal int
                        codeBuf.emit("COPYI I" + intToString(nextFreeRegI) + " " + $$.name);
                        $$.place = nextFreeRegI;
                        $$.type = cmm_int;
                        ++nextFreeRegI;
                    }
                }
            |
                CALL { 
                    $$.place = $1.place;
                    $$.type = $1.type;
                }
;

// function call
CALL:
                id_tok '(' CALL_ARGS ')'{
                    map<string, FunctionInformation>::iterator itr = implementedFunctions.find($1.name);
                    bool implemented = false;
                    if ( itr != implementedFunctions.end()) {
                        implemented = true;
                    }
                    else {
                        itr = declaredFunctions.find($1.name);
                        if (itr == declaredFunctions.end()) {
                            semanticError("undeclared function '" + $1.name + "'");
                        }
                    }
                    /* found a function implementation/declaration */
                    FunctionInformation &func = itr->second;
                    if ( func.argTypes != $3.argTypes ) {
                        semanticError("bad function call"); // TODO: elaborate on error
                    }

                    /* start function call procedure */
                    
                    int savedStateOffset = 0;
                    // save local registers
                    for (int i=0; i < nextFreeRegI; ++i) {
                        codeBuf.emit("STORI I" + intToString(i) + " I2 " + intToString(savedStateOffset));
                        savedStateOffset += 4;
                    }

                    // store a float representation of I2 for use in all STORF operations
                    codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I2");

                    for (int i=0; i < nextFreeRegF; ++i) {
                        codeBuf.emit("STORF F" + intToString(i) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset));
                        savedStateOffset += 4;
                    }

                    // store arguments for callee
                    for (int i=$3.argRegs.size() - 1; i >= 0; --i) {
                        if ( $3.argTypes[i] == cmm_float) {
                            codeBuf.emit("STORF F" + intToString($3.argRegs[i]) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset));
                        }
                        else {
                            codeBuf.emit("STORI I" + intToString($3.argRegs[i]) + " I2 " + intToString(savedStateOffset));
                        }
                        savedStateOffset += 4;
                    }

                    // save space for return value
                    savedStateOffset += 4;

                    // update frame and stack pointers to start of callee's frame
                    codeBuf.emit("ADD2I I2 I2 " + intToString(savedStateOffset));
                    codeBuf.emit("COPYI I1 I2");

                    // finally we can call the poor fella, good luck mate
                    if ( !implented ) { 
                        func.callLocations.push_back(codeBuf.nextquad());
                    }
                    codeBuf.emit("JLINK " + intToString(func.locationInFile));

                    // now we have returned, need to restore our state and save the return value

                    codeBuf.emit("SUB2I I2 I2 " + intToString(savedStateOffset));

                    int restoredStateOffset = 0;
                    for (int i=0; i < nextFreeRegI; ++i) {
                        codeBuf.emit("LOADI I" + intToString(i) + " I2 " + intToString(restoredStateOffset));
                        restoredStateOffset += 4;
                    }

                    // float representation of I2 for use in loadf
                    codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I2");

                    for (int i=0; i < nextFreeRegF; ++i) {
                        codeBuf.emit("LOADF F" + intToString(i) + " F" + intToString(nextFreeRegF) + " " + intToString(restoredStateOffset));
                        restoredStateOffset += 4;
                    }

                    // save the return value
                    $$.type = func.returnType;
                    if (func.returnType == cmm_float) {
                        codeBuf.emit("LOADF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset - 4)); // TODO: is the -4 needed?
                        $$.place = nextFreeRegF;
                        ++nextFreeRegF;
                    }
                    else if (func.returnType == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I2" + " " + intToString(savedStateOffset - 4)); // TODO: is the -4 needed?
                        $$.place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                }
;

CALL_ARGS:
                CALL_ARGLIST{
                    $$.argTypes = $1.argTypes;
                    $$.argRegs = $1.argRegs;
                }
            |
               /* epsilon */       { 
                    $$.argTypes.clear();
                    $$.argRegs.clear();
                }
;

CALL_ARGLIST:
                CALL_ARGLIST ',' EXP{
					$$.argTypes = $1.argTypes;
					$$.argRegs = $1.argRegs;
					$$.argTypes.push_back($3.type);
					$$.argRegs.push_back($3.place);       
                }
            |
                EXP  {
					$$.argTypes.push_front($1.type); /* TODO: do we need to clear $1 */
                    $$.argRegs.push_front($1.place); 
                 }
;

M: 
				/*epsilon*/ {
					$$.quad = codeBuf.nextQuad();
				}
;

N:
				/*epsilon*/ {
				$$.nextList = codeBuf.nextQuad();
				codeBuf.emit("UJUMP ");
				}
;
%%

void yyerror(const char* msg)
{
    cerr << "Syntax error: " << yytext << " in line number " << yylineno << endl;
    exit(2);
}

void semanticError(string msg) {
    cerr << "Semantic error: " << msg << " in line number " << yylineno << endl;
    exit(3);
}