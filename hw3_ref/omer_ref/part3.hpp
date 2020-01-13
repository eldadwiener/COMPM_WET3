/* 046266 Compilation Methods, EE Faculty, Technion                        */
/* part3.hpp - Helper functions for project part 3 - API definitions D&A	   */

#ifndef PART3_H
#define PART3_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm> // for find func
#include <fstream> 
#include <vector>
#include <string> 
#include <sstream>
#include <map>

using namespace std;
enum basicType { t_int = 2, t_float = 3, t_struct = 4, t_void = 5};



typedef struct _ParserNode {
    basicType type;
	string value; // the name of the variable
	int tmpReg; // Number of temporal register where we hold the value
	int lineInRsk; // The line where the token be in the .rsk file
	int offset; 
	vector<int> nextList;
	vector<int> falseList;
	vector<int> trueList;
	vector<basicType> paramTypes; // hold the parameters types for function input arguments
	vector<int> paramRegs; // hold the register numbers for function input arguments
	
} ParserNode;

typedef struct _Symbol {
	map<int, basicType> typeMap; // holding for each symbol it's current depthMap. first is depth, second is type
	map<int, int> offsetMap; //offset vector, align to start of the memory, correspond to the correct memory (float and int)
							 // first is depth, second is register number
	int depth; // the depthest block id which has this symbol
} Symbol;

typedef struct _OurStruct {
	string name;
	vector<string> namesI;
	vector<string> namesF;
	vector<basicType> varTypeOrder;
	vector<string> localDefinedStruct;
} OurStruct;


class Buffer {
	private:
		vector<string> data;
	public:
		Buffer();
		void emitEnd(const string& str);
		void emitFront(const string& str); 
		void backpatch(vector<int> holes, int lineNum);
		int nextQuad(); // return the next empty line in the buffer;
		string print(); 
};

typedef struct _Function {
	bool definedInFile; // if the function implementation is in the file
	vector<basicType> paramTypes; // the type of input parameters
	vector<int> callLines; // all the lines where this func is being called
	basicType returnType; // type of the returning var
	int startLineInFile; //The line of the func start her implementation
} Function;


//Globals:
static map<string, Symbol> symbolsTable; 
static map<string, Function> functionsTable;
static vector<OurStruct> definedStructs; // for each depth level we save all the struct names we know (defined in the scope)
static basicType currentReturnType; 
static int nextFreeRegI = 3; // next empty register I
static int nextFreeRegF = 3; // next empty register F
static int currentDepth = 0;  // Current depth in blocks relatively to the most outer block
static vector<string> currentParamInsertionOrder; // actual function parameters 
static vector<string> tmpParamInsertionOrder; // reverse function parameters 
static Buffer *buffer;
static Buffer globalBuffer;
static int currentScopeOffset = 0;
static int prevScopeOffset = 0;
extern FILE *yyin;
bool has_suffix(const std::string &str, const std::string &suffix);
string to_stringOur(int num);
vector<int> merge(vector<int> vec1, vector<int> vec2);
vector<basicType> merge(vector<basicType> vec1, vector<basicType> vec2);
#define YYSTYPE ParserNode
#define FIRST_DEPTH 0

#endif //PART3_H
