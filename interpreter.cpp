#include "interpreter.h"

void Interpreter::validate(const Token& token, TokenType type)
{
    if(token.type != type)
        throw std::runtime_error("Expected "+get_token_name(type)+" ,found "+get_token_name(token.type));
}

int Interpreter::factor()
{
    // factor = integer | "(", expression, ")"
    auto next = lexer.next();
    if(next.type == TOKEN_LPAREN){
        auto expr = expression();
        next = lexer.next();
        validate(next, TOKEN_RPAREN);
        return expr;
    }
    validate(next, TOKEN_INTEGER);
    return next.value.ival;
}
int Interpreter::term()
{
    // term = factor, {"*", "/", factor}
    auto lhs = factor();
    while(lexer.has_next()){
        auto op = lexer.next();
        if(op.type == TOKEN_STAR || op.type == TOKEN_FSLASH){
            auto rhs = factor();
            lhs = compute(lhs, rhs, op);
        }
        else{
            // Some other token is found
            lexer.unget(op);
            return lhs;
        }
    }
    return lhs;
}

int Interpreter::expression()
{

    // expression = term, {"+" | "-", term}
    auto lhs = term();
    while(lexer.has_next()){
        auto op = lexer.next();
        if(op.type == TOKEN_PLUS || op.type == TOKEN_MINUS){
            auto rhs = term();
            lhs = compute(lhs, rhs, op);
        }
        else{
            lexer.unget(op);
            return lhs;
        }
    }
    return lhs;
}
int Interpreter::compute(int l, int r, Token op)
{
    switch(op.type){
        case TOKEN_PLUS:
            return l + r;
        case TOKEN_MINUS:
            return l - r;
        case TOKEN_STAR:
            return l * r;
        case TOKEN_FSLASH:
            return l / r;
        default:
            throw std::runtime_error("Expected operator(+, -, /, *),found "+get_token_name(op.type));
    }
}