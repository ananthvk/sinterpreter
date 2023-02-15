#pragma once
#include "token.h"
#include <string>

// A class which represents a lexer and produces tokens from the source file
class Lexer
{
  private:
    // current_pos is the index in the string, from where the next token has to
    // be read
    int current_pos;
    std::string source;
    Token ungetted;
    bool is_unget;
    // If any operator is found, sets it to the token reference and returns true
    // else returns false
    bool scan_operator(Token &token);
    // Skip whitespaces, useful for processing operators such as '+', etc.
    void skip_spaces();

  public:
    // Default constructor
    Lexer() : current_pos(0), source(""), ungetted(), is_unget(false) {}
    // Constructor to set the source program
    Lexer(const std::string &source)
        : current_pos(0), source(source), ungetted(), is_unget(false)
    {
    }
    // Returns the length of the source file
    int srclength();
    // Returns true if there are any more tokens which have to be processed
    bool has_next();
    // Returns the next token in the stream
    Token next();
    // Ungets a token - i.e. stores the token and on the next call to next,
    // returns it
    void unget(Token token);

    inline void set_source(const std::string &source) { this->source = source; }
    inline void set_pos(int new_pos) { this->current_pos = new_pos; }
};