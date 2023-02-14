#include "lexer.h"

int Lexer::srclength()
{
    return source.size();
}

bool Lexer::has_next()
{
    return current_pos < srclength();
}

Token Lexer::next()
{
    skip_spaces();

    if(!has_next())
        return Token();

    // Process single character operators
    switch(source[current_pos]){

    }
}

void Lexer::skip_spaces()
{
    while(has_next() && std::isspace(source[current_pos]))
        current_pos++;
}