/* 046266 Compilation Methods, EE Faculty, Technion                        */
/* part3_helpers.h - Helper functions for project part 3 - API definitions */

#ifndef PART3_HELPERS_H
#define PART3_HELPERS_H

#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

enum types { cmm_int, cmm_float, cmm_pint, cmm_void, cmm_volatile };

string intToString(int num);

class CodeBuffer {
    public:
        void emit(string code);
        void backPatch(vector<int>& list, int quad);
        int nextQuad();
		void merge(vector<int>& src1, vector<int>& src2, vector<int>& dst);
        string getCodeString();
    private:
        vector<string> code;
};

class Node {
    public:
        string name; // id of node if applicable 
        types type; // type of param, if applicable
        int offset; // offset from I1, this is where the variable is located in the stack if applicable
        int offsetReg; // for dereferenced pointers, this register contains the offset to the LVAL
        bool dereferencedPtr;
        int quad; // quad for use in markers
        int place; // register number allocated for this nodes intermediate value.
        vector<int> nextList;
        vector<int> falseList;
        vector<int> trueList;

        // remember declaration params
        vector<string> argDefinitions;
        // remember function args to check if call is good
        vector<types> argTypes;
        // List of parameters register numbers
        vector<int> argRegs; 
};

class Symbol {
    public:
        Symbol(int offset, types type);
        int offset;
        types type;
};

class SymbolTable {
    public:
        void enterBlock(); // mark a new depth level was entered
        void leaveBlock(); // remove the deepest level
        bool putVar(string varName, Symbol var);
        Symbol getVar(string varName);
		void clear();
    private:
        list<map<string, Symbol> > symTable;

};

class FunctionInformation {
    public:
        vector<types> argTypes;
		vector<string> argNames;
        types returnType;
        int locationInFile;
        vector<int> callLocations;
};

static SymbolTable symTable;
static map<string, FunctionInformation> implementedFunctions;
static map<string, FunctionInformation> declaredFunctions;
static CodeBuffer codeBuf;
static int nextFreeRegI = 3; // next empty int reg
static int nextFreeRegF = 0; // next empty float reg
static int funcStartingLine; // save the first line off the func implementation 
static int currentStackOffset = 0;
static types functionReturnType;
static pair<string, FunctionInformation> pendingFunc;
#define YYSTYPE Node
extern FILE *yyin;
#endif