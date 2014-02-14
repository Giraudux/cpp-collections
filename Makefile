all: prepare map

prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

map: prepare
	gcc -W -Wall -g ./src/test.cpp -o ./build/dictionary -lstdc++

clean:
	@if [ -d ./build ] ; then rm -r ./build ; fi;
