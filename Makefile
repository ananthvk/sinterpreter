CXX=clang++
CXXFLAGS=-W -Wall -Wextra -pedantic -gdwarf-4 -O0 -fsanitize=address,undefined -pedantic -Wno-sign-conversion -Wno-sign-compare

build: main.cpp interpreter.cpp token.cpp
	$(CXX) $(CXXFLAGS) main.cpp interpreter.cpp token.cpp -o main

run: build
	./main