all: prepare map

prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

map: prepare
	gcc -W -Wall -g ./src/map/test.cpp -o ./build/map -lstdc++

clean:
	@if [ -d ./build ] ; then rm -r ./build ; fi;
