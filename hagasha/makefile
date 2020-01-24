# Makefile for part2

rx-cc: part3.tab.cpp part3.tab.hpp part3-lex.c part3-lex.h part3_helpers.cpp part3_helpers.hpp
	g++ -o $@ part3.tab.cpp part3-lex.c part3_helpers.cpp

part3-lex.c part3-lex.h: part3.lex part3_helpers.hpp part3.tab.hpp
	flex part3.lex

part3.tab.cpp part3.tab.hpp: part3.ypp part3_helpers.hpp
	bison -d part3.ypp

.PHONY: clean
clean:
	rm -f rx-cc part3-lex.c part3-lex.h *.o part3.tab.cpp part3.tab.hpp
