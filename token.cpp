#include "token.h"
std::string get_token_name(TokenType type){
    switch(type){
        case TOKEN_EOF: 
            return "EOF";
            break;
        case TOKEN_INTEGER:
            return "INTEGER";
            break;
        case TOKEN_FSLASH:
            return "FORWARD SLASH";
            break;
        case TOKEN_STAR:
            return "STAR";
            break;
        case TOKEN_PLUS:
            return "PLUS";
            break;
        case TOKEN_MINUS:
            return "MINUS";
            break;
        case TOKEN_LPAREN:
            return "LPAREN";
            break;
        case TOKEN_RPAREN:
            return "RPAREN";
            break;
        default:
            return "UNKNOWN";
            break;
    }
}

std::ostream& operator<<(std::ostream &os, const Token& token){
    return os<<"Token<"<<get_token_name(token.type)<<" "<<token.str_value<<">";
}