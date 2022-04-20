CC=gcc
CFLAGS=-lfl

SOURCES=test.l

PROG=text.txt

EXECUTABLE=a.out

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(PROG)

a.out:
	flex $(SOURCES)
	$(CC) $(CFLAGS) lex.yy.c -o $(EXECUTABLE)

clean:
	rm -rf lex.yy.c $(EXECUTABLE)