#include<iostream>
#include"lexer.h"
#include "token.h"
int main()
{
    std::string line;
    while(std::getline(std::cin, line)){
        Lexer lex(line);
        Token tok;
        while(lex.has_next())
        {
            tok = lex.next();
            std::cout<<tok<<" ";
        }
    }
    
}