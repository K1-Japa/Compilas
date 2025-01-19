all:
	clear
	flex lexical.l
	yacc -v -d syntax.y
	g++ -w y.tab.c -o run
	./run < code.txt