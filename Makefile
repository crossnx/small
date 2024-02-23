CMAKE = cmake
CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Debug

all: configure build run

configure:
	$(CMAKE) $(CMAKE_FLAGS) -B build

build: configure
	$(CMAKE) --build build

run: ./build/small_runtime
	./build/small_runtime ./index.js

clean: build
	rm -rf build

