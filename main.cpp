#include<iostream>
#include "token.h"
int main()
{
    std::cout<<"hello world\n";
    Token token;
    token.type = TOKEN_INTEGER;
    token.value.ival = 312;
    token.str_value = "312";
    std::cout<<token<<"\n";
    int a = 4;
}