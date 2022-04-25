#
# >>> Template of a Makefile <<<
#
# target: prerequisite
#     command
# 
# Useful macros:
#
#  $@: the name of the file to be made.
#
#  $?: the names of the changed dependents.#
#
#  $<: the name of the related file that caused the action.
#
#  $^: The filenames of all the prerequisites, separated by spaces.
#     This list has duplicate filenames removed since for most uses,
#     such as compiling, copying, etc., duplicates are not wanted.
#
#  $+: Similar to $^, this is the names of all the prerequisites separated
#     by spaces, except that $+ includes duplicates. This variable was created
#     for specific situations such as arguments to linkers where duplicate
#     values have meaning.
#
#  $*: the prefix shared by target and dependent files.
#
#  $%: The filename element of an archive member specification.
#
# More info: 
#     https://www.tutorialspoint.com/makefile/makefile_macros.htm
#     https://www.tutorialspoint.com/makefile/makefile_quick_guide.htm
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=out

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) *.o 