%option noyywrap

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include "Funkcije.hpp"
#include "parser.tab.hpp"

using namespace std;

extern void yyerror(string s);
%}

%%
"function" { return function_token;}
"value" { return value_token; }
"sin"   { return sin_token;   }
"cos"   { return cos_token;   }
[abcdefgh] {yylval.c = yytext[0]; return id_token;}
[0-9]+ { yylval.b = atof(yytext); return num_token; }
[x=\(\)+\-*\\"\n\[\]\']      { return *yytext; }
[ \t]           { ; }
.                 { cerr << "Neprepoznat karakter: " << yytext << endl; exit(-1); }
%%
