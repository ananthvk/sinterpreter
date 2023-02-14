#pragma once
#include "token.h"
#include<string>

// A class which represents a lexer and produces tokens from the source file
class Lexer
{
    private:
        // current_pos is the index in the string, from where the next token has to be read
        int current_pos;
        std::string source;
    public:
        // Constructor to set the source program
        Lexer(const std::string& source): source(source){}
        // Returns the length of the source file
        int srclength();
        // Returns true if there are any more tokens which have to be processed
        bool has_next();
        // Returns the next token in the stream
        Token next();
        // Skip whitespaces, useful for processing operators such as '+', etc.
        void skip_spaces();
};