#pragma once
#include "lexer.h"
#include <iostream>
#include <string>

class Interpreter
{
  private:
    Lexer lexer;
    // Check if the token is of the type
    void validate(const Token &token, TokenType type);

  public:
    // Initialize the interpreter with a lexer on a source file
    Interpreter(const Lexer &lexer) : lexer(lexer) {}
    // Parses and returns the result of a mathematical expression from the
    // current token Incase of error, raises an logic_error expression = term,
    // {"+" | "-", term}
    int expression();
    // term = factor, {"*", "/", factor}
    int term();
    // factor = integer
    int factor();
    // Simple compute method between two values
    int compute(int l, int r, Token op);
};