# Alexis Giraudet
# Théo Cesbron

all: test

prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

test: prepare
	gcc -W -Wall -g ./src/parser_dictionnaire.cpp -o ./build/parse -lstdc++ -std=c++0x #-std=c++11

clean:
	@if [ -d ./build ] ; then rm -r ./build ; fi;
