#include "interpreter.h"

void Interpreter::validate(const Token &token, TokenType type)
{
    if (token.type != type)
        throw std::runtime_error("Expected " + get_token_name(type) +
                                 " ,found " + get_token_name(token.type));
}

int Interpreter::factor()
{
    // factor = {"+" | "-"} integer | {"+" | "-"} "(", expression, ")"
    int sign = get_plus_minus_equiv();
    if(!(sign == 1 || sign == -1))
        sign = 1;
    auto next = lexer.next();
    if (next.type == TOKEN_LPAREN)
    {
        auto expr = expression();
        next = lexer.next();
        validate(next, TOKEN_RPAREN);
        return expr*sign;
    }
    validate(next, TOKEN_INTEGER);
    return next.value.ival*sign;
}
int Interpreter::term()
{
    // term = factor, {"*", "/", {"-" | "+"}factor}
    auto lhs = factor();
    while (lexer.has_next())
    {
        auto op = lexer.next();
        if (op.type == TOKEN_STAR || op.type == TOKEN_FSLASH)
        {
            int sign = get_plus_minus_equiv();
            if(!(sign == 1 || sign == -1))
                sign = 1;
            auto rhs = factor();
            lhs = compute(lhs, sign*rhs, op.type);
            
        }
        else
        {
            // Some other token is found
            lexer.unget(op);
            return lhs;
        }
    }
    return lhs;
}

int Interpreter::get_plus_minus_equiv()
{
    Token next = lexer.next();

    if (!(next.type == TOKEN_PLUS || next.type == TOKEN_MINUS))
    {
        lexer.unget(next);
        return 0; // To signify an error
    }

    int sign = 1;
    while (next.type == TOKEN_PLUS || next.type == TOKEN_MINUS)
    {
        if (next.type == TOKEN_MINUS)
            sign *= -1;

        next = lexer.next();
    }
    lexer.unget(next);
    return sign;
}
int Interpreter::expression()
{
    // expression = term, {{"+" | "-"}, term}
    auto lhs = term();
    while (lexer.has_next())
    {
        auto sign = get_plus_minus_equiv();
        if (sign == 1 || sign == -1)
        {
            auto rhs = term();
            lhs = compute(lhs, rhs, sign==1?TOKEN_PLUS:TOKEN_MINUS);
        }
        else{
            break;
        }
    }
    return lhs;
}
int Interpreter::compute(int l, int r, TokenType op)
{
    switch (op)
    {
    case TOKEN_PLUS:
        return l + r;
    case TOKEN_MINUS:
        return l - r;
    case TOKEN_STAR:
        return l * r;
    case TOKEN_FSLASH:
        return l / r;
    default:
        throw std::runtime_error("Expected operator(+, -, /, *),found " +
                                 get_token_name(op));
    }
}