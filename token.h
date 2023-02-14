#ifndef TOKEN_H_
#define TOKEN_H_
#include<string>
#include<ostream>
enum TokenType{
    TOKEN_EOF,
    TOKEN_INTEGER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN
};

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
    Token(){
        type = TOKEN_EOF;
        value.ival = 0;
        str_value = "";
    }
};

std::string get_token_name(const Token& token);
std::ostream& operator<<(std::ostream &os, const Token& token);

#endif // TOKEN_H_