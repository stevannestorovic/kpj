%option noyywrap
%option nounput

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include "Matrix.hpp"
#include "parser.tab.hpp"

using namespace std;
%}



%%
"print"   { return print_token; }
"Matrix"  { return matrix_token; }
[+-]?[0-9]+(\.[0-9]*)? { return num_token; }
[a-z][0-9]*   { return id_token; }
[;+*\-\[\]\(\)=,]  { return *yytext; }
[ \t\n]   { ; }
.         { cerr << "Leksicka greska, neprepoznat karakter: " << yytext << endl; exit(-1); }
 
%%
