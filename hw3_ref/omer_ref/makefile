# Makefile part2
CCC = g++ -std=c++11
CXXLINK = $(CCC)
OBJS = part3.o lex.yy.c part3.tab.cpp
RM = rm -f

# Creating the executable
rx-cc:  $(OBJS)
	$(CXXLINK) -o rx-cc $(OBJS)
	
# Creating the lexical analyzer source file using flex tool
lex.yy.c: part3.lex part3.tab.hpp part3.hpp
	flex -o lex.yy.c part3.lex

# Creating the parser source file using bison tool
part3.tab.cpp part3.tab.hpp: part3.ypp part3.hpp
	bison -d part3.ypp

part3.o: part3.cpp part3.hpp

# Cleaning old files before new make
clean:
	$(RM) rx-cc $(OBJS) part3.tab.hpp part3.o part3.tab.o
