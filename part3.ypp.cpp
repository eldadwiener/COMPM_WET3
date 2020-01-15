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
BLK:            '{' STLIST '}' {
                                    $$ = makeNode("BLK", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
;

// variable declaration
DCL:            id_tok ':' TYPE {
                                    $$ = makeNode("DCL", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
            |
                id_tok ',' DCL {
                                    $$ = makeNode("DCL", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
;

// variable type
TYPE:
                int_tok { $$ = makeNode("TYPE", NULL, $1); }
            |
                float_tok { $$ = makeNode("TYPE", NULL, $1); }
            |
                void_tok { $$ = makeNode("TYPE", NULL, $1); }
            |
                int_tok'@' {
                                $$ = makeNode("TYPE", NULL, $1);
                                concatList($1, $2);
                                }
            |
                volatile_tok int_tok {
                                        $$ = makeNode("TYPE", NULL, $1);
                                        concatList($1, $2);
                                        }
// statement list
STLIST:
                STLIST STMT {
                                $$ = makeNode("STLIST", NULL, $1);
                                concatList($1, $2);
                                }
            |
               /* epsilon */       { $$ = makeNode("STLIST", NULL, makeNode("EPSILON", NULL, NULL)); }
;

// from here we start defining various statement types
STMT:
                DCL ';' {
                            $$ = makeNode("STMT", NULL, $1);
                            concatList($1, $2);
                            }
            |
                ASSN { $$ = makeNode("STMT", NULL, $1); }
            |
                EXP ';' {
                            $$ = makeNode("STMT", NULL, $1);
                            concatList($1, $2);
                            }
            |
                CNTRL { $$ = makeNode("STMT", NULL, $1); }
            |
                READ { $$ = makeNode("STMT", NULL, $1); }
            |
                WRITE { $$ = makeNode("STMT", NULL, $1); }
            |
                RETURN { $$ = makeNode("STMT", NULL, $1); }
            |
                BLK { $$ = makeNode("STMT", NULL, $1); }
            |
                ASSN_C{ $$ = makeNode("STMT", NULL, $1); }
;

RETURN:
                return_tok EXP ';'{
                                    $$ = makeNode("RETURN", NULL, $1);
                                    concatList($1, $2);
                                    concatList($1, $3);
                                    }
            |
                return_tok';'{
                                $$ = makeNode("RETURN", NULL, $1);
                                concatList($1, $2);
                                }
;


WRITE:
                write_tok '(' EXP ')' ';'{
                                            $$ = makeNode("WRITE", NULL, $1);
                                            concatList($1, $2);
                                            concatList($1, $3);
                                            concatList($1, $4);
                                            concatList($1, $5);
                                            }
            |
                write_tok '(' str_tok ')' ';'{
                                                $$ = makeNode("WRITE", NULL, $1);
                                                concatList($1, $2);
                                                concatList($1, $3);
                                                concatList($1, $4);
                                                concatList($1, $5);
                                                }
;

READ:
                read_tok '(' LVAL ')' ';'{
                                                $$ = makeNode("READ", NULL, $1);
                                                concatList($1, $2);
                                                concatList($1, $3);
                                                concatList($1, $4);
                                                concatList($1, $5);
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
                LVAL assign_tok BEXP '?' EXP ':' EXP ';' {
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