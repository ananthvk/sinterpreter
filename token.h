#pragma once
#include<string>
#include<ostream>

enum TokenType{
    TOKEN_EOF,
    TOKEN_INTEGER,
    TOKEN_OPERATOR,
};

// Represents a token, implemented as a tagged union with type containing the token type
// str value is the string representation of the value and value is the actual value.
struct Token{
    TokenType type;
    std::string str_value;
    union Value { 
        int ival;
        char cval;
        double fval;
        bool bval;
        char opval;
    } value;
    // By default the type of token is EOF with value 0
    Token(){
        type = TOKEN_EOF;
        value.ival = 0;
        str_value = "";
    }
};

// Returns the string representation of the token type
std::string get_token_name(const Token& token);
std::ostream& operator<<(std::ostream &os, const Token& token);
