#include "token.h"
std::string get_token_name(const Token& token){
    switch(token.type){
        case TOKEN_EOF: 
            return "EOF";
            break;
        case TOKEN_INTEGER:
            return "INTEGER";
            break;
        case TOKEN_OPERATOR:
            return "OPERATOR";
            break;
        default:
            return "UNKNOWN";
            break;
    }
}

std::ostream& operator<<(std::ostream &os, const Token& token){
    return os<<"Token<"<<get_token_name(token)<<" "<<token.str_value<<">";
}