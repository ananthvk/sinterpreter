#include<iostream>
#include"lexer.h"
#include "token.h"
int main()
{
    std::string line;
    std::cout<<"Sinterpreter - type 'exit' to quit\n";
    while(std::getline(std::cin, line)){
        if(line == "exit")
            break;
    }
    
}