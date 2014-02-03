all: prepare map

prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

map: prepare
	gcc -Wall -g ./src/map/test.cpp -o ./build/map -lstdc++

clean:
	@if [ -d ./build ] ; then rm -r ./build ; fi;
