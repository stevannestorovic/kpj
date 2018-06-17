parser: lex.yy.c parser.tab.cpp Matrix.cpp
	g++ -o $@ $^

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<

lex.yy.c: lexer.l parser.tab.hpp
	flex $<

.PHONY: clean
clean: 
	rm -f *.tab.* lex.yy.c parser
