%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include <string>
#include "parser.tab.hpp"

using namespace std;
extern void yyerror(string s);
%}

%%

-?[0-9]+ {yylval.broj = atof(yytext); return num_token;}
[a-zA-Z_][a-zA-Z_0-9]* {yylval.ime = new string(yytext); return id_token;}
[=;+*/\-] {return *yytext;}
[ \t\n] {;}
.       {yyerror("Lesicka greska, neprepoznat karakter");}

%%
