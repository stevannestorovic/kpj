%option noyywrap

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "parser.tab.hpp"

using namespace std;

extern void yyerror(string s);
%}

%%
"print"  {return print_token;}
"vector" {return vector_token;}
[a-z][0-9]* {yylval.ime = new string(yytext);return vector_id_token;}
[0-9]+      {yylval.br = atof(yytext);return num_token;}
[;=,\[\]]    {return *yytext;}
[ \n\t]     {;}
.           {yyerror("Leksiskca greska, poyy");}
%%
