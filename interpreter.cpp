#include "interpreter.h"

void Interpreter::validate(const Token& token, TokenType type)
{
    if(token.type != type)
        throw std::runtime_error("Expected "+get_token_name(type)+" ,found "+get_token_name(token.type));
}
int Interpreter::factor()
{
    auto next = lexer.next();
    validate(next, TOKEN_INTEGER);
    return next.value.ival;
}
int Interpreter::term()
{
    auto lhs = factor();
    while(lexer.has_next()){
        auto op = lexer.next();
    }
}