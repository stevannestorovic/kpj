%option noyywrap
%option nounput

%{
#include <iostream>
#include <cstdio>
#include <string>
#include "Skup.hpp"
#include "parser.tab.hpp"
using namespace std;
extern void yyerror(string s);
%}

%%
print {return print_token;}
[A-Z] { yylval.ime = new string(yytext);
           return id_token;}
[0-9]+ {yylval.broj = atof(yytext);return num_token;}
[;,={}]  {return *yytext;}
[ \n\t]  {;}
".."     {return range_token;}
.        {yyerror("Leksiskca greska, neprepoznat token");}
%%
