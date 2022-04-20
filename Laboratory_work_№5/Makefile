CC=g++
CFLAGS=

BISONSOURCES=input.y
FLEXSOURCES=input.l

EXECUTABLE=a.out

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) text.txt

a.out:
	bison -dy $(BISONSOURCES)
	flex $(FLEXSOURCES)
	$(CC) $(CFLAGS) lex.yy.c y.tab.c TNode.cpp -o $(EXECUTABLE)

clean:
	rm -rf lex.yy.c y.tab.h y.tab.c $(EXECUTABLE)
