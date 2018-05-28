CXX=gcc
CFLAGS =  -c -Wall -Werror -std=c99
FLAGS  =  -Wall -Werror -std=c99
OBJECTS = build/main.o build/Check.o

.PHONY: clean all bin build

all: bin build default

default: bin/prog

bin/prog: $(OBJECTS) 
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/prog

build/main.o: src/main.c src/func.h
	$(CXX) $(CFLAGS) src/main.c -o build/main.o

build/Check.o: src/Check.c src/func.h
	$(CXX) $(CFLAGS) src/Check.c -o build/Check.o

build:
	mkdir build
bin:
	mkdir bin 
clean:
	-rm -rf build bin
