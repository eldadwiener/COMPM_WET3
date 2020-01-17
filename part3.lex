%{
#include <stdio.h>
#include <stdlib.h>
#include "part3_helpers.hpp"
#include "part3.tab.hpp"

void LexErr();
void printstr();
%}

%option yylineno noyywrap
%option   outfile="part3-lex.c" header-file="part3-lex.h"

digit       ([0-9])
letter      ([a-zA-Z])
newline     (\r?\n)
whitespace  ([\t ]|{newline})
id          {letter}({letter}|{digit}|_)*
num         {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
str         (\"([^"\\\n]?(\\["n\\])?)*\")
sign        [(){}?,:;&@]
comment     #(.*)
rel         ("=="|"<>"|"<"|"<="|">"|">=")
addsub      ("+"|"-")
muldiv      ("*"|"/")


%%
int                              { return int_tok; }
float                            { return float_tok; }
void                             { return void_tok; }
write                            { return write_tok; }
read                             { return read_tok; }
while                            { return while_tok; }
do                               { return do_tok; }
if                               { return if_tok; }
then                             { return then_tok; }
else                             { return else_tok; }
return                           { return return_tok; }
volatile                         { return volatile_tok; }
{sign}                           { yylval.name = yytext[0] ; return yytext[0]; }
{id}                             { yylval.name = strdup(yytext) ; return id_tok; }
{num}                            { yylval.name = strdup(yytext) ; return num_tok; }
{str}                            {
                                    yytext[yyleng - 1] = 0;
                                    yylval.name = strdup(yytext + 1) ;
                                    return str_tok;
                                 }
{rel}                            { yylval.name = strdup(yytext) ; return relop_tok; }
{addsub}                         { yylval.name = yytext[0] ; return addop_tok; }
{muldiv}                         { yylval.name = yytext[0] ; return mulop_tok; }
"="                              { return assign_tok; }
"&&"                             { return and_tok; }
"||"                             { return or_tok; }
"!"                              { return not_tok; }
{whitespace}                     ;
{comment}                        ;
.                                LexErr();
%%

void LexErr()
{
    printf("\nLexical error: '%s' in line number %d\n", yytext, yylineno);
    exit(1);
}


