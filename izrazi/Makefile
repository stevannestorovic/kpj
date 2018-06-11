parser: parser.tab.cpp lex.yy.c
	g++ -o parser $^

parser.tab.hpp  parser.tab.cpp: parser.ypp
	bison -d $<


lex.yy.c: lexer.l parser.tab.hpp
	flex $<

.PHONY: clean


clean:
	rm -f *.tab.* *.yy.c parser 
