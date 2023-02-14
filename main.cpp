#include<iostream>
#include "token.h"
#include "interpreter.h"
int main()
{
    std::string line;
    std::cout<<"Sinterpreter - type 'exit' to quit\n";
    while(std::getline(std::cin, line)){
        if(line == "exit")
            break;
        Interpreter inter(line);
        inter.expression();
        std::cout<<">>";
        /*
        Token tok = inter.get_next_token();
        while(tok.type !=TOKEN_EOF)
        {
            std::cout<<tok<<"\n";
            tok = inter.get_next_token();
        }
        */
        
    }
    
}