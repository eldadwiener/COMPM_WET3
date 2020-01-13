/* 046266 Compilation Methods, EE Faculty, Technion                        */
/* part3_helpers.cpp - Helper functions for project part 3 - implementation  */
#include <stdio.h>
#include "part3_helpers.hpp"

void CodeBuffer::emit(string code) {
    this->code.push_back(code);
}

void CodeBuffer::backPatch(vector<int>& list, int quad) {
    for( int i=0; i< list.size; ++i) {
        int codeLineToChange = list[i];
        this->code[codeLineToChange] += " " + intToString(quad);
    }
}

int CodeBuffer::nextQuad() {
    return this->code.size();
}

 
void SymbolTable::enterBlock() {
	map <string, Symbol> newMap;
	symTable.push_back(newMap);
}

void SymbolTable::leaveBlock() {
	symTable.pop_back();
}

bool SymbolTable::putVar(string varName, Symbol var) {
	map <string, Symbol > myMap = symTable.back();
	if (myMap.find(varName) != myMap.end()) //allready exist
	{
		return false;
	}
	myMap.insert(std::pair<string, Symbol>(varName, var));
	return true;
}

Symbol SymbolTable::getVar(string varName) {
	list<map <string, Symbol>>::reverse_iterator rit = symTable.rbegin();
	for (; rit != symTable.rend(); ++rit) {
		map <string, Symbol> & curMap = (*rit);
		map <string, Symbol>::iterator itr = curMap.find(varName);
		if (itr != curMap.end()) {
			return itr->second;
		}
	}
	return NULL;
}
