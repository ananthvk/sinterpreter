#pragma once
#include <ostream>
#include <string>

enum TokenType
{
    TOKEN_EOF,
    TOKEN_INTEGER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_FSLASH,
    TOKEN_LPAREN,
    TOKEN_RPAREN
};

// Represents a token, implemented as a tagged union with type containing the
// token type str value is the string representation of the value and value is
// the actual value.
struct Token
{
    TokenType type;
    std::string str_value;
    union Value
    {
        int ival;
        char cval;
        double fval;
        bool bval;
    } value;
    // By default the type of token is EOF with value 0
    Token()
    {
        type = TOKEN_EOF;
        value.ival = 0;
        str_value = "";
    }
    Token(TokenType type) : type(type), str_value("") { value.ival = 0; }
};

// Returns the string representation of the token type
std::string get_token_name(TokenType token);
std::ostream &operator<<(std::ostream &os, const Token &token);
