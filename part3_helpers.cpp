/* 046266 Compilation Methods, EE Faculty, Technion                        */
/* part3_helpers.cpp - Helper functions for project part 3 - implementation  */
#include <stdio.h>
#include "part3_helpers.hpp"
#include <sstream>
#include <iostream>

string intToString(int num) {
  std::ostringstream stream;
  stream << std::dec << num;
  return stream.str();
}

void CodeBuffer::emit(string code) {
    this->code.push_back(code);
}

void CodeBuffer::backPatch(vector<int>& list, int quad) {
    for( int i=0; i< list.size(); ++i) {
        int codeLineToChange = list[i];
        code[codeLineToChange - 1] = code[codeLineToChange - 1] + " " + intToString(quad);
    }
}

int CodeBuffer::nextQuad() {
    return this->code.size() + 1;
}

void CodeBuffer::merge(vector<int>& src1, vector<int>& src2, vector<int>& dst) {
	vector<int> tmp;
	tmp.insert(tmp.end(), src1.begin(), src1.end());
	tmp.insert(tmp.end(), src2.begin(), src2.end());
	dst = tmp;
}

string CodeBuffer::getCodeString() {
	string out = "";
	for (int i=0; i < code.size(); ++i) {
		out += code[i] + "\n";
	}
	return out;
}

Symbol::Symbol(int offset, types type): offset(offset), type(type) {}

void SymbolTable::enterBlock() {
	map <string, Symbol> newMap;
	symTable.push_back(newMap);
}

void SymbolTable::leaveBlock() {
	symTable.pop_back();
}

bool SymbolTable::putVar(string varName, Symbol var) {
	map <string, Symbol > &myMap = symTable.back();
	if (myMap.find(varName) != myMap.end()) //allready exist
	{
		return false;
	}
	myMap.insert(std::pair<string, Symbol>(varName, var));
	return true;
}

void SymbolTable::clear() {
	symTable.clear();
}

Symbol SymbolTable::getVar(string varName) {
	list<map <string, Symbol> >::reverse_iterator rit = symTable.rbegin();
	for (; rit != symTable.rend(); ++rit) {
		map <string, Symbol> & curMap = (*rit);
		map <string, Symbol>::iterator itr = curMap.find(varName);
		if (itr != curMap.end()) {
			return itr->second;
		}
	}
	Symbol errSymbol(-1,cmm_int);
	return errSymbol;
}
