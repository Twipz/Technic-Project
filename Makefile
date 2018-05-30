CXX=gcc
CFLAGS =  -c -Wall -Werror -std=c99
FLAGS  =  -Wall -Werror -std=c99
OBJECTS = build/main.o build/Check.o build/Check_data.o

OB = build/main_test.o build/Check.o build/Check_data.o

.PHONY: clean all bin build bin/sudoku bin/sud_test default test

all: bin build bin/sudoku bin/sud_test default test

default: bin/sudoku/prog

test: bin/sud_test/prog_test
	bin/sud_test/prog_test

bin/sudoku/prog: $(OBJECTS) 
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/sudoku/prog

build/main.o: src/main.c src/func.h
	$(CXX) $(CFLAGS) src/main.c -o build/main.o

build/Check.o: src/Check.c src/func.h
	$(CXX) $(CFLAGS) src/Check.c -o build/Check.o

build/Check_data.o: src/Check_data.c src/func.h
	$(CXX) $(CFLAGS) src/Check_data.c -o build/Check_data.o


bin/sud_test/prog_test: $(OB)
	$(CXX) $(FLAGS) $(OB) -o bin/sud_test/prog_test

build/main_test.o: Test/main_test.c src/func.h thirdparty/ctest.h
	$(CXX) $(CFLAGS) -I thirdparty -I src -c Test/main_test.c -o build/main_test.o

build:
	mkdir build
bin:
	mkdir bin
bin/sudoku:
	mkdir bin/sudoku
bin/sud_test:
	mkdir bin/sud_test
clean:
	-rm -rf build bin
