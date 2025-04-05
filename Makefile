all: clean build run

clean:
	rm -rf build

build:
	mkdir build
	cd build && qmake ../notes.pro && make >> /dev/null

run:
	./build/notes.app/Contents/MacOS/notes


.PHONY: clean build all
