%{
/* Declarations section */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> //TODO !!!
#include "part3.hpp"
#include "part3.tab.hpp"
void errorToken();
/* When we compile this file with a C++ compiler, it declares that the function yylex must be compiled with "C linkage", */
/* so that C functions can call it without trouble.*/
extern "C" int yylex(); //TODO !!!
%}

%option yylineno
%option noyywrap

digit			([0-9])
letter			([a-zA-Z])
whitespace		([\t ])
newLine			(\n|\r\n|\r)
keywords		(int|float|struct|void|write|read|while|do|if|then|else|return)
signs			([(){},:;.])
relop			(==|<>|<|<=|>|>=)
addop			([+-])
mulop			([*/])
assign			(=)
and				(&&)
or				(\|\|)
not				(!)
id				{letter}({letter}|{digit}|_)*
num				{digit}+(\.{digit})?({digit})*
comment			(#.*[^\n])
str				(\"(\\.|[^"\n])*\")


%%
{keywords}	{
				yylval.value = strdup(yytext);
				if (!strcmp("int", yytext)) return t_INT;
				else if (!strcmp("float", yytext)) return t_FLOAT;
				else if (!strcmp("struct", yytext)) return t_STRUCT;
				else if (!strcmp("void", yytext)) return t_VOID;
				else if (!strcmp("write", yytext)) return t_WRITE;
				else if (!strcmp("read", yytext)) return t_READ;
				else if (!strcmp("while", yytext)) return t_WHILE;
				else if (!strcmp("do", yytext)) return t_DO;
				else if (!strcmp("if", yytext)) return t_IF;
				else if (!strcmp("then", yytext)) return t_THEN;
				else if (!strcmp("else", yytext)) return t_ELSE;
				else return t_RETURN;
			}
{id}		{
				yylval.value = strdup(yytext);
				return t_ID;
			}
{num}		{
				yylval.value = strdup(yytext);
				return t_NUM;
			}
{relop}		{
				yylval.value = strdup(yytext);
				return t_RELOP;
			}
{addop}		{
				yylval.value = strdup(yytext);
				return t_ADDOP;
			}
{mulop}		{
				yylval.value = strdup(yytext);
				return t_MULOP;
			}
{assign}	{
				yylval.value = strdup(yytext);
				return t_ASSIGN;
			}
{and}		{
				yylval.value = strdup(yytext);
				return t_AND;
			}
{or}		{
				yylval.value = strdup(yytext);
				return t_OR;
			}
{not}		{
				yylval.value = strdup(yytext);
				return t_NOT;
			}
{signs}		{
				yylval.value = strdup(yytext);
				return yytext[0];
			}
{whitespace} ; /* we don't want whitespace in semantic tree */
{str}		{
				char* ourString = yytext+1; /* need to remove " from the beginning of the string */
				ourString[yyleng-2] = 0; /* need to remove " from the end of the string */
				yylval.value = strdup(ourString);
				return t_STR;
			}
{comment}	; /* we don't want comment in semantic tree */
{newLine}	; /* we don't want newLine in semantic tree */
.				errorToken();

%%
void errorToken(){
	printf("Lexical error: \'%s\' in line number %d\n", yytext, yylineno);
	exit(1);
}
