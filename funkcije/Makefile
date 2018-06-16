parser: parser.tab.cpp lex.yy.c Funkcije.cpp
	g++ -o $@ $^
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d $<
lex.yy.c: lexer.l parser.tab.hpp
	flex lexer.l

.PHONY: clean
clean: 
	rm -f *.tab.* lex.yy.c parser 
