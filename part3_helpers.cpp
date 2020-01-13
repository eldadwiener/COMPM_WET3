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

}

void SymbolTable::leaveBlock() {

}

bool SymbolTable::putVar(string varName, Symbol var) {

}

Symbol SymbolTable::getVar(string varName) {

}
