CXX=clang++
CXXFLAGS=-W -Wall -Wextra -pedantic -gdwarf-4 -O0 -fsanitize=address,undefined  -pedantic -Wno-sign-conversion -Wno-sign-compare
OBJ_DIR=build

build: $(OBJ_DIR)/token.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/main.o $(OBJ_DIR)/interpreter.o
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/token.o $(OBJ_DIR)/main.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/interpreter.o -o main

$(OBJ_DIR)/token.o: token.cpp
	$(CXX) $(CXXFLAGS) token.cpp -c -o $(OBJ_DIR)/token.o

$(OBJ_DIR)/lexer.o: lexer.cpp
	$(CXX) $(CXXFLAGS) lexer.cpp -c -o $(OBJ_DIR)/lexer.o

$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/interpreter.o: interpreter.cpp
	$(CXX) $(CXXFLAGS) interpreter.cpp -c -o $(OBJ_DIR)/interpreter.o

tokenizer:$(OBJ_DIR)/token.o $(OBJ_DIR)/lexer.o tokenizer.cpp
	$(CXX) $(CXXFLAGS) tokenizer.cpp $(OBJ_DIR)/token.o  $(OBJ_DIR)/lexer.o -o tokenizer


run: build
	./main

clean:
	rm -f build/*
	rm main

rebuild: clean build
