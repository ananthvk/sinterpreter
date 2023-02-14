#pragma once
#include "token.h"
#include <iostream>
#include <string>

class Interpreter
{
  private:
    std::string source;
    int current_pos;
    bool in_bounds()
    {
        if (current_pos >= source.size())
            return false;
        return true;
    }

  public:
    Interpreter(const std::string &source) : source(source), current_pos(0) {}
    Token get_next_token();
    void skip_whitespaces(){
        while(current_pos < source.length() && std::isspace(source[current_pos])){
            current_pos++;
        }
    }
    void expression();
    Token expect(TokenType type);
};