/* 046266 Compilation Methods, EE Faculty, Technion                        */
/* part3.cpp - main c code for project part 3 - implementation D&A		   */

#include "part3.hpp"
string to_stringOur(int num){
	ostringstream tmp;
	tmp << num;
	return tmp.str();
}

vector<int> merge(vector<int> vec1, vector<int> vec2){
	vector<int> res = vec1;
	res.insert(res.end(), vec2.begin(), vec2.end());
	return res;
}

vector<basicType> merge(vector<basicType> vec1, vector<basicType> vec2){
	vector<basicType> res = vec1;
	res.insert(res.end(), vec2.begin(), vec2.end());
	return res;
}

Buffer::Buffer(){
	data.clear();
}

int Buffer::nextQuad(){
	return data.size()+1;
}

string Buffer::print(){
	string str = "";
	for(int i=0; i < data.size(); i++)
		str+= data[i] + "\n";
	return str;
}

void Buffer::emitEnd(const string& str){
	data.push_back(str);
}

void Buffer::emitFront(const string& str){
	data.insert(data.begin(),str);
}

void Buffer::backpatch(vector<int> holes, int lineNum){
	for(int i=0;i< holes.size();i++)
		data[holes[i]-1] += to_stringOur(lineNum) + " ";
}

bool has_suffix(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}