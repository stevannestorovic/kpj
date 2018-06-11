parser: parser.tab.cpp lex.yy.c
	g++ -o parser $^

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
lex.yy.c: lexer.l parser.tab.hpp
	flex $<

.PHONY: clean

clean:
	rm -f *.tab.* *.yy.c parser parser.output
