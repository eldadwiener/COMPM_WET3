
%{
	#include "part3.hpp"
	extern "C" int yylex();
	extern char* yytext;
	extern int yylineno;
	extern void yylex_destroy();
	
	void yyerror(const char* msg); /* our error function - will return error in case of syntax error */
	void yyerrorSemantic(string msg); /* our error function - will return error in case of semantic error */
	void yyerrorOperational(string msg); /* our error function - will return error in case of operational error */
	

%}
	
	/* Token Definitions:
	We will avoid conflicts by ordering the tokens according to their priority - the lowest token has the highest priority */
	
	%token t_INT t_FLOAT t_STRUCT t_VOID
	%token t_WRITE t_READ
	%token t_WHILE t_DO t_RETURN
	%token t_ID t_NUM t_STR
	%right t_IF t_THEN t_ELSE
	%right t_ASSIGN
	%left t_OR
	%left t_AND	
	%left t_RELOP 
	%left t_ADDOP
	%left t_MULOP
	%right t_NOT
	%left ','
	%left ':'
	%left '.'
	%left '(' ')'
	%left '{' '}'
	%left ';'
	
%%

/* Parsing Rule Definitions:
	this is actually our grammar, we will build sub tree for each rule in the grammar,
	again here if there were two token definition with the same priority, now we can
	solve this, again via the order of the derivative rules */

PROGRAM:		TDEFS FDEFS
				{
					// Filling all the holes with function address
					for(map<string, Function>::iterator it = functionsTable.begin(); it != functionsTable.end(); it++) {
						buffer->backpatch(it->second.callLines, it->second.startLineInFile);
					}
					buffer->emitEnd("HALT");
				}
;
TDEFS:			TDEFS t_STRUCT t_ID '{' DECLARELIST '}' ';'
				{	
					// find this struct is already exist
					for(vector<OurStruct>::iterator it = definedStructs.begin(); it != definedStructs.end(); it++)
						if ((*it).name == $3.value)
							yyerrorSemantic("struct already exists. struct is:" + $3.value);
					// if we here, we need to enter new struct
					OurStruct newStruct;
					newStruct.name = $3.value;
					for (int i=0; i < currentParamInsertionOrder.size(); i++){
						string name = currentParamInsertionOrder[i];
						basicType newType = symbolsTable[name].typeMap[FIRST_DEPTH];
						if (newType == t_int){
							newStruct.namesI.push_back(name);
							newStruct.varTypeOrder.push_back(t_int);
						}
						else if (newType == t_float){
							newStruct.namesF.push_back(name);
							newStruct.varTypeOrder.push_back(t_float);
						} 
						else
							yyerrorSemantic("invalid type: " + newType);
						symbolsTable.erase(name);
					
					}
					//std::reverse(newStruct.varTypeOrder.begin(),newStruct.varTypeOrder.end());
					std::reverse(newStruct.varTypeOrder.begin(),newStruct.varTypeOrder.end());
					
					definedStructs.push_back(newStruct);
					currentParamInsertionOrder.clear();

				}
				| /*epsilon*/ 
				{
				}
;
FDEFS:			FDEFS FUNC_API BLK
				{
					//Implemented function in file
					// Check that this function has not already exist in this file
					if(functionsTable[$2.value].definedInFile == true) {
						yyerrorSemantic("multiple definition of same function in file. function: '" + $2.value + "'");
					}
					functionsTable[$2.value].definedInFile = true;	
					
					buffer->emitEnd("RETRN");

					// Initialize the relevant globals 
					nextFreeRegI = 3;
					nextFreeRegF = 3;
					currentScopeOffset = 0;
					symbolsTable.clear();
					$2.paramTypes.clear(); 
				}
				|
				FDEFS FUNC_API ';'
				{
					// Function not implemented function in file - only deceleration
					if ($2.value == "main")
						yyerrorSemantic("probably, there are two main");
					if (functionsTable[$2.value].definedInFile == false) 
						functionsTable[$2.value].startLineInFile = -1;
					
					symbolsTable.clear();
				}
				| /*epsilon*/
				{
				}
;
FUNC_API:		TYPE t_ID '(' M FUNC_ARGS ')' 
				{
					// check that main return type is void
					if($2.value == "main" && $1.type != t_void)
						yyerrorSemantic("main is not returning void");
					
					// find this func is already exist
					if (functionsTable.find($2.value) != functionsTable.end()){
						//verify return type
						if (functionsTable[$2.value].returnType != $1.type)
							yyerrorSemantic("return type doesn't match. function:" + $2.value);
						//verify arguments amount
						if ($5.paramTypes.size() != functionsTable[$2.value].paramTypes.size())
							yyerrorSemantic("arguments number doesn't match. function:" + $2.value);
						// TO_DO: check that if we get a struct that it is defined in our file
						//verify arguments type
						for (int i=0; i< functionsTable[$2.value].paramTypes.size(); i++)
							if (functionsTable[$2.value].paramTypes[i] != $5.paramTypes[i])
								yyerrorSemantic("aaaaarguments types doesn't match. function: " + $2.value + " a type: " + to_stringOur(functionsTable[$2.value].paramTypes[i]) + " b type: " + to_stringOur($5.paramTypes[i]));
						if (functionsTable[$2.value].definedInFile == false && functionsTable[$2.value].startLineInFile == -1) 
							yyerrorSemantic("dup deceleration. function:" + $2.value);
						// if the function not defined yet, it is now the implementation and we save the start line to next line
						if (functionsTable[$2.value].definedInFile == false)
							functionsTable[$2.value].startLineInFile = $4.lineInRsk;
					}
					else {
						
						Function newFunc;
						newFunc.returnType = $1.type;
						newFunc.startLineInFile = $4.lineInRsk;
						newFunc.paramTypes = $5.paramTypes;
						newFunc.definedInFile = false;
						
						functionsTable.insert(pair<string,Function>($2.value,newFunc));
					}
					
					currentReturnType = $1.type;
					$$.value = $2.value;
					$$.type = $1.type;
					$$.lineInRsk = $4.lineInRsk;
					$$.paramTypes = $5.paramTypes;
					currentParamInsertionOrder.clear();
					$5.paramTypes.clear();
				}
;
FUNC_ARGS:		FUNC_ARGLIST
				{
					vector<basicType> paramTypesVec;
					int offset = -4; // in bytes 

					for (int i=0; i < currentParamInsertionOrder.size() ; i++){
						string name = currentParamInsertionOrder[i];
						basicType newType = symbolsTable[name].typeMap[FIRST_DEPTH];
						paramTypesVec.push_back(newType);
						offset -= 4;
						symbolsTable[name].offsetMap[FIRST_DEPTH] = offset;
						
						//currentScopeOffset += 4; //removed after testing primeNumber fail. call to fun mod even if it is empty
					}

					$$.paramTypes = paramTypesVec;
					
					currentParamInsertionOrder.clear();
					currentScopeOffset += offset + 4;
					
				}	
				| /*epsilon*/
				
				{
				}	
;
FUNC_ARGLIST:	FUNC_ARGLIST ',' DCL
				{
					//in order to get the function parameters in correct order
					for (int i=tmpParamInsertionOrder.size() - 1; i>=0; i--){
						string name = tmpParamInsertionOrder[i];
						currentParamInsertionOrder.push_back(name);
					}
					tmpParamInsertionOrder.clear();
				}
				| 
				DCL
				{
					
					for (int i=tmpParamInsertionOrder.size() - 1; i>=0; i--){
						string name = tmpParamInsertionOrder[i];
						currentParamInsertionOrder.push_back(name);
					}
					tmpParamInsertionOrder.clear();

				}
;
BLK:			'{' OPEN_BLOCK STLIST M CLOSE_BLOCK '}'
				{
					buffer->backpatch($3.nextList, $4.lineInRsk);
				}
;				
OPEN_BLOCK:			/*epsilon*/
				{
					// when we enter to new block, it means we in one depth size
					currentDepth++;	
				}
;
CLOSE_BLOCK:			/*epsilon*/
				{
					for(map<string, Symbol>::iterator it = symbolsTable.begin(); it != symbolsTable.end(); it++){
						if (it->second.depth == currentDepth) {
							it->second.typeMap.erase(currentDepth);
							it->second.offsetMap.erase(currentDepth);
							// we need to retrive the previous max depth for each symbol (varaible)
							int max = 0;
							for (map<int, basicType>::iterator it_max = it->second.typeMap.begin(); it_max != it->second.typeMap.end(); it_max++)
								if (it_max->first > max)
									max = it_max->first;
							it->second.depth = max;
							
							//it->second.depth--;	
						}
					}
					currentDepth--;	
				}
;
DECLARELIST:	DECLARELIST DCL ';'
				{
				
					//in order to get the struct parameters in correct order
					for (int i=tmpParamInsertionOrder.size() - 1; i>=0; i--){
						string name = tmpParamInsertionOrder[i];
						currentParamInsertionOrder.push_back(name);
					}
					tmpParamInsertionOrder.clear();

				}
				|
				DCL ';'
				{
					for (int i=tmpParamInsertionOrder.size() - 1; i>=0; i--){
						string name = tmpParamInsertionOrder[i];
						currentParamInsertionOrder.push_back(name);
					}
					tmpParamInsertionOrder.clear();
				}
;
DCL:			t_ID ':' TYPE
				{
					if ($3.type == t_void)
						yyerrorSemantic("var tried to be defined as void:" + $1.value);
					// check not override function input arguments
					if (find(currentParamInsertionOrder.begin(), currentParamInsertionOrder.end(), $1.value) != currentParamInsertionOrder.end())
						yyerrorSemantic("overriding function arguments, argument is:" + $1.value);
					
					prevScopeOffset = currentScopeOffset;
					$$.value = $1.value;
					$$.type = $3.type;
					$$.offset = currentScopeOffset;
					//check if symbol defined
					if (symbolsTable.find($1.value) == symbolsTable.end()){
						Symbol newSymbol;
						newSymbol.depth = currentDepth;
						newSymbol.typeMap[currentDepth] = $3.type;
						
						if ($3.type == t_int){
							newSymbol.offsetMap[currentDepth] = currentScopeOffset;
							//nextFreeRegI++;
						} else { // only float, for void we exit at start of this function
							newSymbol.offsetMap[currentDepth] = currentScopeOffset;
							//nextFreeRegF++;
						}
						symbolsTable.insert(pair<string,Symbol>($1.value,newSymbol));
						tmpParamInsertionOrder.push_back($1.value);
					}
					else { //symbol is already defined
						// check that the symbol is not already defined in our depth level
						if (symbolsTable[$1.value].typeMap.find(currentDepth) != symbolsTable[$1.value].typeMap.end())
							yyerrorSemantic("We have duplicate var definition in the same block. var is:" + $1.value);
						//if no error, we add another id in our block depth
						symbolsTable[$1.value].depth = currentDepth;
						symbolsTable[$1.value].typeMap[currentDepth] = $3.type;
						if ($3.type == t_int){
							symbolsTable[$1.value].offsetMap[currentDepth] = currentScopeOffset;
							//nextFreeRegI++;
						} else { // only float, for void we exit at start of this function
							symbolsTable[$1.value].offsetMap[currentDepth] = currentScopeOffset;
							//nextFreeRegF++;
						}
					}
					currentScopeOffset += 4;
					
				}
				|
				t_ID ':' t_ID
				{
					// check that the struct is already defined
					int notSeenAtAll = 0;
					if ((symbolsTable.find($1.value) != symbolsTable.end()) && (symbolsTable[$1.value].typeMap.find(currentDepth) != symbolsTable[$1.value].typeMap.end()))
						yyerrorSemantic("the struct name already in use. name is:" + $1.value);
					vector<OurStruct>::iterator it;
					for(it = definedStructs.begin(); it != definedStructs.end(); it++)
						if ((*it).name == $3.value){ 
							notSeenAtAll = 1;
							break;
						}
					if (notSeenAtAll == 0)
						yyerrorSemantic("the struct is not defined, struct is:" + $3.value);
					if (std::find((*it).localDefinedStruct.begin(),(*it).localDefinedStruct.end(),$1.value) == (*it).localDefinedStruct.end())
							(*it).localDefinedStruct.push_back($1.value);
					$$.value = $3.value;
					$$.type = t_struct;
					int intIndex=0;
					int floatIndex=0;
					// now the struct already defined and we need to save it vars in memory (in symbol table)
					for (int i=0; i < (*it).varTypeOrder.size(); i++){
						if ((*it).varTypeOrder[i] == t_int){
							string newName = $1.value + "." + (*it).namesI[intIndex];
							tmpParamInsertionOrder.push_back(newName);
							//check if symbol defined
							if (symbolsTable.find(newName) == symbolsTable.end()){ //new name not defined yet
								Symbol newSymbol;
								newSymbol.depth = currentDepth;
								newSymbol.typeMap[currentDepth] = t_int;
								newSymbol.offsetMap[currentDepth] = currentScopeOffset;
								symbolsTable.insert(pair<string,Symbol>(newName, newSymbol));
							}
							else { //new name is already defined
								// check that the symbol is not already defined in our depth level
								if (symbolsTable[newName].typeMap.find(currentDepth) != symbolsTable[newName].typeMap.end())
									yyerrorSemantic("we have duplicate var definition in the same block. var is:" + newName);
								//if no error, we add another id in our block depth
								symbolsTable[newName].depth = currentDepth;
								symbolsTable[newName].typeMap[currentDepth] = t_int;
								symbolsTable[newName].offsetMap[currentDepth] = currentScopeOffset;
							}	
							intIndex++;
						} else {

							string newName = $1.value + "." + (*it).namesF[floatIndex];
							tmpParamInsertionOrder.push_back(newName);
							if (symbolsTable.find(newName) == symbolsTable.end()){ //new name not defined yet
								Symbol newSymbol;
								newSymbol.depth = currentDepth;
								newSymbol.typeMap[currentDepth] = t_float;
								newSymbol.offsetMap[currentDepth] = currentScopeOffset;
								symbolsTable.insert(pair<string,Symbol>(newName, newSymbol));
							}
							else { //new name is already defined
								// check that the symbol is not already defined in our depth level
								if (symbolsTable[newName].typeMap.find(currentDepth) != symbolsTable[newName].typeMap.end())
									yyerrorSemantic("we have duplicate var definition in the same block. var is:" + newName);
								//if no error, we add another id in our block depth
								symbolsTable[newName].depth = currentDepth;
								symbolsTable[newName].typeMap[currentDepth] = t_float;
								symbolsTable[newName].offsetMap[currentDepth] = currentScopeOffset;
							}
							floatIndex++;
						}
						currentScopeOffset += 4;
					}
				}
				|
				t_ID ',' DCL
				{
					if ($3.type == t_void)
						yyerrorSemantic("var tried to be defined as void:" + $1.value);

					// Check in both lists that an id with the same name does not exist in the currrent function/struct list parameters
					if (find(tmpParamInsertionOrder.begin(), tmpParamInsertionOrder.end(), $1.value) != tmpParamInsertionOrder.end())
						yyerrorSemantic("repeated definition of parameter '" + $1.value + "'");
					
					if (find(currentParamInsertionOrder.begin(), currentParamInsertionOrder.end(), $1.value) != currentParamInsertionOrder.end())
						yyerrorSemantic("repeated definition of parameter '" + $1.value + "'");
					
					$$.value = $1.value;
					$$.type = $3.type;

					if ($3.type == t_int || $3.type == t_float){ //lets, first of all, determine if it struct or regular vars
						if (symbolsTable.find($1.value) == symbolsTable.end()){
							Symbol newSymbol;
							newSymbol.depth = currentDepth;
							newSymbol.typeMap[currentDepth] = $3.type;
							if ($3.type == t_int){
								newSymbol.offsetMap[currentDepth] = currentScopeOffset;
								//nextFreeRegI++;
							} else { // only float, for void we exit at start of this function
								newSymbol.offsetMap[currentDepth] = currentScopeOffset;
								//nextFreeRegF++;
							}
							symbolsTable.insert(pair<string,Symbol>($1.value,newSymbol));
							tmpParamInsertionOrder.push_back($1.value);
						}
						else { //symbol is already defined
							// check that the symbol is not already defined in our depth level
							if (symbolsTable[$1.value].typeMap.find(currentDepth) != symbolsTable[$1.value].typeMap.end())
								yyerrorSemantic("we have duplicate var definition in the same block. var is:" + $1.value);
							//if no error, we add another id in our block depth
							symbolsTable[$1.value].depth = currentDepth;
							symbolsTable[$1.value].typeMap[currentDepth] = $3.type;
							if ($3.type == t_int){
								symbolsTable[$1.value].offsetMap[currentDepth] = currentScopeOffset;
								//nextFreeRegI++;
							} else { // only float, for void we exit at start of this function
								symbolsTable[$1.value].offsetMap[currentDepth] = currentScopeOffset;
								//nextFreeRegF++;
							}
						}
					currentScopeOffset += 4;
					
					}else { //this is struct
						// check that the struct is already defined
						int notSeenAtAll = 0;
						vector<OurStruct>::iterator it;
						for(it = definedStructs.begin(); it != definedStructs.end(); it++)
							if ((*it).name == $3.value){ 
								notSeenAtAll = 1;
								break;
							}
						if (notSeenAtAll == 0)
							yyerrorSemantic("the struct is not defined, struct is:" + $3.value);
						if (std::find((*it).localDefinedStruct.begin(),(*it).localDefinedStruct.end(),$1.value) == (*it).localDefinedStruct.end())
							(*it).localDefinedStruct.push_back($1.value);

						$$.value = $1.value;
						$$.type = $3.type;
						int intIndex=0;
						int floatIndex=0;
						// now the struct already defined and we need to save it vars in memory (in symbol table)
						for (int i=0; i < (*it).varTypeOrder.size(); i++){
							if ((*it).varTypeOrder[i] == t_int){
								string newName = $1.value + "." + (*it).namesI[intIndex];
								if (symbolsTable.find(newName) == symbolsTable.end()){ //new name not defined yet
									Symbol newSymbol;
									newSymbol.depth = currentDepth;
									newSymbol.typeMap[currentDepth] = t_int;
									newSymbol.offsetMap[currentDepth] = currentScopeOffset;
									symbolsTable.insert(pair<string,Symbol>(newName, newSymbol));
								}
								else { //new name is already defined
									// check that the symbol is not already defined in our depth level
									if (symbolsTable[newName].typeMap.find(currentDepth) != symbolsTable[newName].typeMap.end())
										yyerrorSemantic("we have duplicate var definition in the same block. var is:" + newName);
									//if no error, we add another id in our block depth
									symbolsTable[newName].depth = currentDepth;
									symbolsTable[newName].typeMap[currentDepth] = t_int;
									symbolsTable[newName].offsetMap[currentDepth] = currentScopeOffset;
								}
								intIndex++;
							} else {
						
								string newName = $1.value + "." + (*it).namesF[floatIndex];
								if (symbolsTable.find(newName) == symbolsTable.end()){ //new name not defined yet
									Symbol newSymbol;
									newSymbol.depth = currentDepth;
									newSymbol.typeMap[currentDepth] = t_float;
									newSymbol.offsetMap[currentDepth] = currentScopeOffset;
									symbolsTable.insert(pair<string,Symbol>(newName, newSymbol));
								}
								else { //new name is already defined
									// check that the symbol is not already defined in our depth level
									if (symbolsTable[newName].typeMap.find(currentDepth) != symbolsTable[newName].typeMap.end())
										yyerrorSemantic("we have duplicate var definition in the same block. var is:" + newName);
									//if no error, we add another id in our block depth
									symbolsTable[newName].depth = currentDepth;
									symbolsTable[newName].typeMap[currentDepth] = t_float;
									symbolsTable[newName].offsetMap[currentDepth] = currentScopeOffset;
								}
								floatIndex++;
							}
							currentScopeOffset += 4;
						}
					}
				}
;
TYPE:				t_INT
				{
					$$.type = t_int;
				}
				|
				t_FLOAT
				{
					$$.type = t_float;
				}
				|
				t_VOID
				{
					$$.type = t_void;
				}
;
STLIST:			STLIST STMT
				{
					
				}
				| /*epsilon*/
				{
					
				}
;
STMT:			DCL ';'
				{
					tmpParamInsertionOrder.clear();
					currentParamInsertionOrder.clear();
					int offset = currentScopeOffset - prevScopeOffset;
					buffer->emitEnd("ADD2I I2 I2 " + to_stringOur(offset));
				}
				|
				ASSN
				{
				}
				|
				EXP ';'
				{
					
				}
				|
				CNTRL M
				{
					// need to backpath all next list of control to next list of statement
					buffer->backpatch($1.nextList, $2.lineInRsk);
				}
				|
				READ
				{
				}
				|
				WRITE
				{
				}
				|
				RETURN
				{
				}
				|
				BLK
				{
				}
;
RETURN:			t_RETURN EXP ';'
				{
					if (currentReturnType != $2.type || currentReturnType == t_void) 
						yyerrorSemantic("return type of the function is not valid. func is:" + $2.value);
					$$.tmpReg = $2.tmpReg;
					int returnOffset = 4; //const. in bytes
					if (currentReturnType == t_int)
						buffer->emitEnd("STORI I" + to_stringOur($2.tmpReg) + " I1 -" + to_stringOur(returnOffset));
					else if (currentReturnType == t_float){
						buffer->emitEnd("CITOF F1 I1");
						buffer->emitEnd("STORF F" + to_stringOur($2.tmpReg) + " F1 -" + to_stringOur(returnOffset));
					}else 
						yyerrorSemantic("return type of the function is not valid. func is:" + $2.value);
					//buffer->emitEnd("LOADI I0 I2 4");
					buffer->emitEnd("RETRN");
				}
				|
				t_RETURN ';'
				{
					buffer->emitEnd("LOADI I0 I2 4");
					if (currentReturnType != t_void)
						yyerrorSemantic("return type of the function must be void. current return type is: " + currentReturnType);
					buffer->emitEnd("RETRN");
				}
;
WRITE:			t_WRITE '(' EXP ')' ';'
				{
					if ($3.type == t_int)
						buffer->emitEnd("PRNTI I" + to_stringOur($3.tmpReg));
					else if ($3.type == t_float)
						buffer->emitEnd("PRNTF F" + to_stringOur($3.tmpReg));
					else
						yyerrorSemantic("can't print struct! ");
				}
				|
				t_WRITE '(' t_STR ')' ';'
				{
					for (int i=0; i < $3.value.length() ; i++){
						char c = $3.value[i];
						if (c == '\\') {
							if ($3.value[i+1] == 'n') {
								c = '\n';
								i++;
							}
							else if ($3.value[i+1] == 't') {
								c = '\t';
								i++;
							}
							else if ($3.value[i+1] == 'r') {
								c = '\r';
								i++;
							}
							else if ($3.value[i+1] == '"') {
								c = '\"';
								i++;
							}
						}
						int asciiChar = static_cast<int>(c);
						buffer->emitEnd("PRNTC " + to_stringOur(asciiChar));
					}
				}
;
READ:			t_READ '(' LVAL ')' ';'
				{
					if ($3.type == t_int){
						int tmpI = nextFreeRegI;
						buffer->emitEnd("READI I" + to_stringOur(tmpI));
						buffer->emitEnd("STORI I" + to_stringOur(tmpI) + " I" + to_stringOur($3.tmpReg) + " 0");
						nextFreeRegI++;
					} else {
						int tmpF = nextFreeRegF;
						buffer->emitEnd("READF F" + to_stringOur(tmpF));
						buffer->emitEnd("STORF F" + to_stringOur(tmpF) + " F" + to_stringOur($3.tmpReg) + " 0");
						nextFreeRegF++;
					}
				}
;
ASSN:			LVAL t_ASSIGN EXP ';'
				{
					if ($1.type != $3.type)
						yyerrorSemantic("assignment of differents types: " + to_stringOur($1.type) + " != " + to_stringOur($3.type));
					if ($1.type == t_void)
						yyerrorSemantic("assignment of non void to void: " + to_stringOur($1.type) + " and " + to_stringOur($3.type));
					if ($1.type == t_int)
						buffer->emitEnd("STORI I" + to_stringOur($3.tmpReg) + " I" + to_stringOur($1.tmpReg) + " 0");
					else if ($1.type == t_float)
						buffer->emitEnd("STORF F" + to_stringOur($3.tmpReg) + " F" + to_stringOur($1.tmpReg) + " 0");
					else
						yyerrorSemantic("you try to assign struct?! type is: " + $1.type);
					
				}
;
LVAL:			t_ID
				{
					// check that the variable is declared
					if (symbolsTable.find($1.value) == symbolsTable.end())
						yyerrorSemantic("undeclared var. var is: " + $1.value);
					int varDepth = symbolsTable[$1.value].depth;
					$$.type = symbolsTable[$1.value].typeMap[varDepth];
					if ($$.type == t_void)
						yyerrorSemantic("declared void var. var is" + $1.value);
					if ($$.type == t_int){
						$$.tmpReg = nextFreeRegI;
						nextFreeRegI++;
						$$.offset = symbolsTable[$1.value].offsetMap[varDepth];
						buffer->emitEnd("ADD2I I" + to_stringOur($$.tmpReg) + " I1 " + to_stringOur($$.offset));
					} else {
						$$.tmpReg = nextFreeRegF;
						nextFreeRegF++;
						$$.offset = symbolsTable[$1.value].offsetMap[varDepth];
						buffer->emitEnd("CITOF F1 I1");
						buffer->emitEnd("ADD2F F" + to_stringOur($$.tmpReg) + " F1 " + to_stringOur($$.offset));
					}
				}
				|
				STRUCT_MEMBER
				{
					//TO_DO !!! - check carefully
					// check that the struct variable is declared
					if (symbolsTable.find($1.value) == symbolsTable.end())
						yyerrorSemantic("undeclared struct member. var is: " + $1.value);
					int varDepth = symbolsTable[$1.value].depth;
					$$.type = symbolsTable[$1.value].typeMap[varDepth];
					if ($$.type == t_void)
						yyerrorSemantic("declared void struct member. var is" + $1.value);
					if ($$.type == t_int){
						$$.tmpReg = nextFreeRegI++;
						$$.offset = symbolsTable[$1.value].offsetMap[varDepth];
						buffer->emitEnd("ADD2I I" + to_stringOur($$.tmpReg) + " I1 " + to_stringOur($$.offset));
					} else {
						$$.tmpReg = nextFreeRegF++;
						$$.offset = symbolsTable[$1.value].offsetMap[varDepth];
						buffer->emitEnd("CITOF F1 I1");
						buffer->emitEnd("ADD2F F" + to_stringOur($$.tmpReg) + " F1 " + to_stringOur($$.offset));
					}
					
				}
;
CNTRL:			t_IF BEXP t_THEN M STMT t_ELSE N M STMT
				{
					buffer->backpatch($2.trueList, $4.lineInRsk);
					buffer->backpatch($2.falseList, $8.lineInRsk);
					$$.nextList = merge($5.nextList, $7.nextList);
					$$.nextList = merge($$.nextList, $9.nextList);
					$5.nextList.clear();
					$7.nextList.clear();
					$9.nextList.clear();
				}
				|
				t_IF BEXP t_THEN M STMT
				{
					buffer->backpatch($2.trueList, $4.lineInRsk);
					$$.nextList = merge($2.falseList, $5.nextList);
					$2.falseList.clear();
					$5.nextList.clear();					
				}
				|
				t_WHILE M BEXP t_DO M STMT
				{
					buffer->backpatch($3.trueList, $5.lineInRsk);
					buffer->backpatch($6.nextList, $2.lineInRsk);
					$$.nextList = $3.falseList;
					buffer->emitEnd("UJUMP " + to_stringOur($2.lineInRsk));

				}
;
BEXP:			BEXP t_OR M BEXP
				{
					buffer->backpatch($1.falseList, $3.lineInRsk);
					$$.falseList = $4.falseList;
					$$.trueList = merge($1.trueList, $4.trueList);
					$1.trueList.clear();
					$4.trueList.clear();
				}
				|
				BEXP t_AND M BEXP
				{
					buffer->backpatch($1.trueList, $3.lineInRsk);
					$$.trueList = $4.trueList;
					$$.falseList = merge($1.falseList, $4.falseList);
					$1.falseList.clear();
					$4.falseList.clear();
				}
				|
				t_NOT BEXP
				{
					$$.trueList = $2.falseList;
					$$.falseList = $2.trueList;
				}
				|
				EXP t_RELOP EXP
				{
					if ($1.type != $3.type)
						yyerrorSemantic("not equal type. var1 type is: " + to_stringOur($1.type) + " var2 type is: " + to_stringOur($3.type));
					if ($1.type == t_void)
						yyerrorSemantic("relop to void. var1 is: " + $1.value);
					string lReg = to_stringOur($1.tmpReg); //left
					string rReg = to_stringOur($3.tmpReg); //right
					if ($1.type == t_int){
						$$.tmpReg = nextFreeRegI++;
						
						$$.falseList.push_back(buffer->nextQuad() + 1); //UJUMP for backpatch
						$$.trueList.push_back(buffer->nextQuad() + 2); //BNEQZ for backpatch
						
						if ($2.value == "=="){
							buffer->emitEnd("SEQUI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BREQZ I" + to_stringOur($$.tmpReg) + " ");
						} else if ($2.value == "<>") {
							buffer->emitEnd("SNEQI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BREQZ I" + to_stringOur($$.tmpReg) + " ");
						} else if ($2.value == "<=") {
							buffer->emitEnd("SGRTI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BNEQZ I" + to_stringOur($$.tmpReg) + " ");
						} else if ($2.value == "<") {
							buffer->emitEnd("SLETI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BREQZ I" + to_stringOur($$.tmpReg) + " ");
						} else if ($2.value == ">=") {
							buffer->emitEnd("SLETI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BNEQZ I" + to_stringOur($$.tmpReg) + " ");
						} else if ($2.value == ">") {
							buffer->emitEnd("SGRTI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
							buffer->emitEnd("BREQZ I" + to_stringOur($$.tmpReg) + " ");
						}
					} else if ($1.type == t_float) {
						$$.tmpReg = nextFreeRegF++;
						nextFreeRegI++; 
						$$.falseList.push_back(buffer->nextQuad() + 1); //UJUMP for backpatch
						$$.trueList.push_back(buffer->nextQuad() + 2); //BNEQZ for backpatch
						
						if ($2.value == "=="){
							buffer->emitEnd("SEQUF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BREQZ I" + to_stringOur(nextFreeRegI) + " ");
						} else if ($2.value == "<>") {
							buffer->emitEnd("SNEQF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BREQZ I" + to_stringOur(nextFreeRegI) + " ");
						} else if ($2.value == "<=") {
							buffer->emitEnd("SGRTF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BNEQZ I" + to_stringOur(nextFreeRegI) + " ");
						} else if ($2.value == "<") {
							buffer->emitEnd("SLETF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BREQZ I" + to_stringOur(nextFreeRegI) + " ");
						} else if ($2.value == ">=") {
							buffer->emitEnd("SLETF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BNEQZ I" + to_stringOur(nextFreeRegI) + " ");
						} else if ($2.value == ">") {
							buffer->emitEnd("SGRTF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
							buffer->emitEnd("CFTOI I" + to_stringOur(nextFreeRegI) + " F" + to_stringOur($$.tmpReg));
							buffer->emitEnd("BREQZ I" + to_stringOur(nextFreeRegI) + " ");
						}
					}
					else 
						yyerrorSemantic("not support type: " + to_stringOur($1.type));
					buffer->emitEnd("UJUMP ");

				}
				|
				'(' BEXP ')'
				{
					$$.trueList = $2.trueList;
					$$.falseList = $2.falseList;
				}
;
EXP:			EXP t_ADDOP EXP
				{
					string lReg = to_stringOur($1.tmpReg); //left
					string rReg = to_stringOur($3.tmpReg); //right
					if ($1.type != $3.type)
						yyerrorSemantic("not equal type. var1 type is: " + to_stringOur($1.type) + " var2 type is: " + to_stringOur($3.type));
					if ($1.type == t_void || $3.type == t_void)
						yyerrorSemantic("addOP to void. var1 is: " + $1.value);
					$$.type = $1.type;
					if ($1.type == t_int){
						$$.tmpReg = nextFreeRegI++;
						if ($2.value == "+")
							buffer->emitEnd("ADD2I I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
						else
							buffer->emitEnd("SUBTI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
					} else if ($1.type == t_float){
						$$.tmpReg = nextFreeRegF++;
						if ($2.value == "+")
							buffer->emitEnd("ADD2F F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
						else
							buffer->emitEnd("SUBTF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
					} else
						yyerrorSemantic("not support type: " + to_stringOur($1.type));
				}
				|
				EXP t_MULOP EXP
				{
					string lReg = to_stringOur($1.tmpReg); //left
					string rReg = to_stringOur($3.tmpReg); //right
					if ($1.type != $3.type)
						yyerrorSemantic("not equal type. var1 type is: " + to_stringOur($1.type) + " var2 type is: " + to_stringOur($3.type));
					if ($1.type == t_void || $3.type == t_void)
						yyerrorSemantic("mulOP to void. var1 is: " + $1.value);
					$$.type = $1.type;
					if ($1.type == t_int){
						$$.tmpReg = nextFreeRegI++;
						if ($2.value == "*")
							buffer->emitEnd("MULTI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
						else
							buffer->emitEnd("DIVDI I" + to_stringOur($$.tmpReg) + " I" + lReg + " I" + rReg);
					} else if ($1.type == t_float){
						$$.tmpReg = nextFreeRegF++;
						if ($2.value == "*")
							buffer->emitEnd("MULTF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
						else
							buffer->emitEnd("DIVDF F" + to_stringOur($$.tmpReg) + " F" + lReg + " F" + rReg);
					} else
						yyerrorSemantic("not support type: " + to_stringOur($1.type));
				}
				|
				'(' EXP ')'
				{
					$$ = $2;
				}
				|
				'(' TYPE ')' EXP
				{
					if ($2.type == t_void || $4.type == t_void)
						yyerrorSemantic("cannot cast to void");
					if ($2.type == $4.type)
						$$ = $4;
					else if ($2.type == t_int && $4.type == t_float) {
						$$.tmpReg = nextFreeRegI++;
						$$.type = $2.type;
						$$.offset = $4.offset;
						buffer->emitEnd("CFTOI I" + to_stringOur($$.tmpReg) + " F" + to_stringOur($4.tmpReg));

					} else if ($2.type == t_float && $4.type == t_int) {
						$$.tmpReg = nextFreeRegF++;
						$$.type = $2.type;
						$$.offset = $4.offset;
						buffer->emitEnd("CITOF F" + to_stringOur($$.tmpReg) + " I" + to_stringOur($4.tmpReg));
					} else
						yyerrorSemantic("casting error. unsuported types");
				}
				|
				t_ID
				{
					// check that the variable is declared
					int isSeen = 0;
					if (symbolsTable.find($1.value) == symbolsTable.end()){
						for(vector<OurStruct>::iterator it = definedStructs.begin(); it != definedStructs.end(); it++){
							if (std::find((*it).localDefinedStruct.begin(),(*it).localDefinedStruct.end(),$1.value) != (*it).localDefinedStruct.end()){
								isSeen = 1;
								string newName;
								
								if ((*it).namesI.size() > 0)
									newName = $1.value + "." + (*it).namesI[0];
								else
									newName = $1.value + "." + (*it).namesF[0];
								$$.type = t_struct;
								$$.value = $1.value;
								$$.paramTypes.clear();
								$$.paramRegs.clear();
								int intIndex = 0;
								int floatIndex = 0;
								for (int i=0; i < (*it).varTypeOrder.size(); i++){
									if ((*it).varTypeOrder[i] == t_int){
										newName = $1.value + "." + (*it).namesI[intIndex];
										int depth = symbolsTable[newName].depth;
										int tmpRegister = nextFreeRegI++;
										int offsetRegister = symbolsTable[newName].offsetMap[depth];
										$$.paramRegs.push_back(tmpRegister);
										$$.paramTypes.push_back(t_int);
										buffer->emitEnd("LOADI I" + to_string(tmpRegister) + " I1 " + to_string(offsetRegister));
										intIndex++;
									} else {
										newName = $1.value + "." + (*it).namesF[floatIndex];
										int depth = symbolsTable[newName].depth;
										int tmpRegister = nextFreeRegF++;
										int offsetRegister = symbolsTable[newName].offsetMap[depth];
										$$.paramRegs.push_back(tmpRegister);
										$$.paramTypes.push_back(t_float);
										buffer->emitEnd("CITOF F1 I1");
										buffer->emitEnd("LOADF F" + to_string(tmpRegister) + " F1 " + to_string(offsetRegister));
										floatIndex++;
									}
								}
								break;
							}
						}
						if (isSeen == 0)
							yyerrorSemantic("struct id or name is not in the symbols table: " + $1.value);
					} else { //regular var
						int depth = symbolsTable[$1.value].depth;
						$$.type = symbolsTable[$1.value].typeMap[depth];
						$$.offset = symbolsTable[$1.value].offsetMap[depth];
						if ($$.type == t_int){
							$$.tmpReg = nextFreeRegI++;
							buffer->emitEnd("LOADI I" + to_stringOur($$.tmpReg) + " I1 " + to_stringOur($$.offset));
						}
						else if ($$.type == t_float){
							$$.tmpReg = nextFreeRegF++;
							buffer->emitEnd("CITOF F1 I1");
							buffer->emitEnd("LOADF F" + to_stringOur($$.tmpReg) + " F1 " + to_stringOur($$.offset));
						} else
							yyerrorSemantic("struct not supported as id!!!");
					}
				}
				|
				STRUCT_MEMBER
				{
					// check that the variable is declared
					int isSeen = 0;
					string varName = $1.value;
					if (symbolsTable.find(varName) == symbolsTable.end())
						yyerrorSemantic("struct_member or name is not in the symbols table: " + varName);
					int depth = symbolsTable[varName].depth;
					$$.type = symbolsTable[varName].typeMap[depth];
					$$.offset = symbolsTable[varName].offsetMap[depth];
					$$.value = varName;
					if ($$.type == t_int){
						$$.tmpReg = nextFreeRegI++;
						buffer->emitEnd("LOADI I" + to_stringOur($$.tmpReg) + " I1 " + to_stringOur($$.offset));
					}
					else if ($$.type == t_float){
						$$.tmpReg = nextFreeRegF++;
						buffer->emitEnd("CITOF F1 I1");
						buffer->emitEnd("LOADF F" + to_stringOur($$.tmpReg) + " F1 " + to_stringOur($$.offset));
					} else
						yyerrorSemantic("struct_member not supported as id2!!!");
				}
				|
				t_NUM
				{
					$$.value = $1.value;
					if ($1.value.find('.') != std::string::npos){ // there is dot in the number
						$$.type = t_float;
						$$.tmpReg = nextFreeRegF++;
						buffer->emitEnd("COPYF F" + to_stringOur($$.tmpReg) + " " + $1.value);
					}else{
						$$.type = t_int;
						$$.tmpReg = nextFreeRegI++;
						buffer->emitEnd("COPYI I" + to_stringOur($$.tmpReg) + " " + $1.value);
					}
				}
				|
				CALL
				{
					$$.tmpReg = $1.tmpReg;
					$$.type = $1.type;
				}
;
STRUCT_MEMBER:	t_ID '.' t_ID
				{
					$$.value = $1.value + "." + $3.value;
				}
				|
				STRUCT_MEMBER '.' t_ID
				{
					$$.value = $1.value + "." + $3.value;
				}
;
CALL:			t_ID '(' CALL_ARGS ')'
				{
					// check if the function is already declerd
					if (functionsTable.find($1.value) == functionsTable.end())
						yyerrorSemantic("dunction not declerd. function name: " + $1.value); 
					//verify arguments amount
					if ($3.paramTypes.size() != functionsTable[$1.value].paramTypes.size())
						yyerrorSemantic("arguments number doesn't match. function:" + $1.value);
					//verify arguments type
					//std::reverse($3.paramTypes.begin(),$3.paramTypes.end());
					
					for (int i=0; i< functionsTable[$1.value].paramTypes.size(); i++)
						if (functionsTable[$1.value].paramTypes[i] != $3.paramTypes[i])
							yyerrorSemantic("arguments types doesn't match. function: " + $1.value + " a type: " + to_stringOur(functionsTable[$1.value].paramTypes[i]) + " b type: " + to_stringOur($3.paramTypes[i]));
					
					//save all registers to memory
					int totalOffset = 0;
					for (int i=0; i < nextFreeRegI; i++){
						buffer->emitEnd("STORI I" + to_stringOur(i) + " I2 " + to_stringOur(totalOffset));
						totalOffset += 4;
					}
					
					for (int i=3; i < nextFreeRegF; i++){
						buffer->emitEnd("CITOF F2 I2");
						buffer->emitEnd("STORF F" + to_stringOur(i) + " F2 " + to_stringOur(totalOffset));
						totalOffset += 4;
					}
					totalOffset += 4; //save place for the return value
					
					int paramCurrentOffset = -4;
					int paramCount = $3.paramRegs.size();
					vector<basicType> paramTypes = $3.paramTypes;
					vector<int> paramRegs = $3.paramRegs;
					vector<int> paramOffset;
					
					$3.paramTypes.clear();
					$3.paramRegs.clear();
					// calc offset in memory for each parameter
					for (int i=0; i< paramCount; i++){
						paramCurrentOffset -= 4;
						totalOffset += 4;
						paramOffset.push_back(paramCurrentOffset);
					}
					
					// I2 = current memory size
					buffer->emitEnd("ADD2I I2 I2 " + to_stringOur(totalOffset));
					currentScopeOffset += totalOffset;
					
					//I1 = I2
					buffer->emitEnd("COPYI I1 I2");
					
					//store all parameters of the calling function in stack
					for (int i=0; i < paramCount; i++){
						if (paramTypes[i] == t_int)
							buffer->emitEnd("STORI I" + to_stringOur(paramRegs[i]) + " I1 " + to_stringOur(paramOffset[i]));
						else{
							buffer->emitEnd("CITOF F1 I1");
							buffer->emitEnd("STORF F" + to_stringOur(paramRegs[i]) + " F1 " + to_stringOur(paramOffset[i]));
						}
					}
					
					// JUMP and LINK
					functionsTable[$1.value].callLines.push_back(buffer->nextQuad());
					buffer->emitEnd("JLINK ");
					
					// returning from the calle func
					buffer->emitEnd("COPYI I2 I1");
					
					$$.type = functionsTable[$1.value].returnType;
					if ($$.type == t_int){
						$$.tmpReg = nextFreeRegI;
						//loading from memory the returning value of the calle func
						buffer->emitEnd("LOADI I" + to_stringOur($$.tmpReg) + " I1 -4");
					}else if ($$.type == t_float){
						$$.tmpReg = nextFreeRegF;
						//loading from memory the returning value of the calle func
						buffer->emitEnd("CITOF F1 I1");
						buffer->emitEnd("LOADF F" + to_stringOur($$.tmpReg) + " F1 -4");
					}
					buffer->emitEnd("SUBTI I2 I2 " + to_stringOur(totalOffset)); //retrive back I1
					
					//bring back all the registers from memoty
					int offsetFunc = 0;

					
					for (int i=0; i < nextFreeRegI; i++){
						buffer->emitEnd("LOADI I" + to_stringOur(i) + " I2 " + to_stringOur(offsetFunc));
						offsetFunc += 4;
					}
					
					for (int i=3; i < nextFreeRegF; i++){
						buffer->emitEnd("CITOF F2 I2");
						buffer->emitEnd("LOADF F" + to_stringOur(i) + " F2 " + to_stringOur(offsetFunc));
						offsetFunc += 4;
					}
					nextFreeRegF++; //maybe we "waste" register in case the return was different type
					nextFreeRegI++; //maybe we "waste" register in case the return was different type
					
					

				}
;
CALL_ARGS:		CALL_ARGLIST
				{
					$$.paramTypes = $1.paramTypes;
					$$.paramRegs = $1.paramRegs;
					$1.paramTypes.clear();
					$1.paramRegs.clear();
				}
				| /*epsilon*/
				{
				}
;
CALL_ARGLIST:	CALL_ARGLIST ',' EXP
				{
					if($3.type == t_struct){		
						std::reverse($3.paramTypes.begin(),$3.paramTypes.end());
						std::reverse($3.paramRegs.begin(),$3.paramRegs.end());
						$$.paramTypes = merge($1.paramTypes, $3.paramTypes);
						$$.paramRegs = merge($1.paramRegs, $3.paramRegs);
						$1.paramTypes.clear();
						$1.paramRegs.clear();
					} else {
						$$.paramTypes = $1.paramTypes;
						$$.paramRegs = $1.paramRegs;
						$$.paramRegs.push_back($3.tmpReg);
						$$.paramTypes.push_back($3.type);
						//$$.paramRegs.insert($$.paramRegs.begin(), $3.tmpReg);
						//$$.paramTypes.insert($$.paramTypes.begin(), $3.type);
						$1.paramTypes.clear();
						$1.paramRegs.clear();
					}
				}
				|
				EXP
				{
					if($1.type == t_struct){
						//cerr << " dannn : " <<endl;
						std::reverse($1.paramTypes.begin(),$1.paramTypes.end());
						$$.paramTypes = $1.paramTypes;
						std::reverse($1.paramRegs.begin(),$1.paramRegs.end());
						$$.paramRegs = $1.paramRegs;
						$$.type = t_struct;
					}
					else {
						//cerr << " aviii : " <<endl;
						//$$.paramRegs.insert($$.paramRegs.begin(), $1.tmpReg);
						//$$.paramTypes.insert($$.paramTypes.begin(), $1.type);
						$$.paramTypes.push_back($1.type);
						$$.paramRegs.push_back($1.tmpReg);
					}
					
				}
;		
M:				{
					$$.lineInRsk = buffer->nextQuad();
				}
;
N:				{
					$$.nextList.push_back(buffer->nextQuad());
					buffer->emitEnd("UJUMP ");
				}
;
%%
int main(int argc, char* argv[]){
	//invalid argument number
	if (argc != 2)
		yyerrorOperational("invalid argument number");
	yyin = fopen(argv[1], "r");
	if (yyin == NULL)
		yyerrorOperational("your input c-- file cannot be read");
	if (has_suffix(argv[1], ".cmm") == false)
		yyerrorOperational("your input c-- file doesn't end with .cmm");
	
	buffer = &globalBuffer;
	yyparse();
	
	globalBuffer.emitFront("</header>");
	string unImplementedFuncs = "<unimplemented>";
	string implementedFuncs = "<implemented>";
	
	for(map<string,Function>::iterator it = functionsTable.begin(); it != functionsTable.end(); it++) {
		if (it->second.definedInFile == true)
			implementedFuncs += " " + it->first + "," + to_stringOur(it->second.startLineInFile);
		else {
			unImplementedFuncs += " " + it->first;
			for (int i=0; i < it->second.callLines.size(); i++)
				unImplementedFuncs += "," + to_stringOur(it->second.callLines[i]);
		}
	}
	globalBuffer.emitFront(implementedFuncs);
	globalBuffer.emitFront(unImplementedFuncs);
	globalBuffer.emitFront("<header>");
	
	ofstream outputRsk;
	string fileName = argv[1];
	size_t lastIndex = fileName.find_last_of("."); 
	string outputRskName = fileName.substr(0, lastIndex) + ".rsk"; 
	
	//find the folder to write to rsk
	size_t folderSep = outputRskName.find_last_of("/\\");
	string folderPath = outputRskName.substr(0,folderSep);
	outputRskName = outputRskName.substr(folderSep+1);
	
	outputRsk.open(folderPath + "/" + outputRskName.c_str());
	outputRsk << globalBuffer.print();
	outputRsk.close();
	
	yylex_destroy();
	return 0;
	
	
	
}
void yyerror(char const* msg) /* our error function - will return error in case of syntax error */
{
	cerr << "Syntax error: " << yytext << " in line number " << yylineno << endl;
	exit(2);
}		
void yyerrorSemantic(string msg) /* our error function - will return error in case of semantic error */
{
	cerr << "Semantic error: " << msg << " in line number " << yylineno << endl;
	exit(3);
}	
void yyerrorOperational(string msg) /* our error function - will return error in case of operational error */
{
	cerr << "Operational error: " << msg << endl;
	exit(9);
}			