#include "lexer.h"

int Lexer::srclength() { return source.size(); }

bool Lexer::has_next() { return (!ungetted.empty()) || current_pos < srclength(); }

bool Lexer::scan_operator(Token &token)
{
    // Process operators here
    bool is_successful = false;
    char ch = source[current_pos];
    switch (ch)
    {
    case '+':
        token.str_value = "+";
        token.type = TOKEN_PLUS;
        is_successful = true;
        break;
    case '-':
        token.str_value = "-";
        token.type = TOKEN_MINUS;
        is_successful = true;
        break;
    case '/':
        token.str_value = "/";
        token.type = TOKEN_FSLASH;
        is_successful = true;
        break;
    case '*':
        token.str_value = "*";
        token.type = TOKEN_STAR;
        is_successful = true;
        break;
    case '(':
        token.str_value = ")";
        token.type = TOKEN_LPAREN;
        is_successful = true;
        break;
    case ')':
        token.str_value = ")";
        token.type = TOKEN_RPAREN;
        is_successful = true;
        break;
    }
    // If the operator was read, increment index in the source by one
    if (is_successful)
        current_pos++;
    return is_successful;
}

Token Lexer::next()
{
    if (!ungetted.empty())
    {
        auto top = ungetted.top();
        ungetted.pop();
        return top;
    }
    Token next_token;
    skip_spaces();

    if (!has_next())
        return Token();

    // Process operators such as +, -, etc

    if (scan_operator(next_token))
    {
        return next_token;
    }

    // Process integers next
    // nonzero digit = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
    // digit = "0" | nonzero digit
    // integer = "0" | ["-"], (nonzero digit, {digit})
    // TODO: Handle the case when negative numbers are entered, such as 3 + -2
    int start_pos = current_pos;
    while (has_next() && std::isdigit(source[current_pos]))
        current_pos++;
    if (start_pos != current_pos)
    {
        next_token.str_value =
            source.substr(start_pos, current_pos - start_pos);
        next_token.type = TOKEN_INTEGER;
        next_token.value.ival = std::stoi(next_token.str_value);
    }
    return next_token;
}

void Lexer::skip_spaces()
{
    while (has_next() && std::isspace(source[current_pos]))
        current_pos++;
}

void Lexer::unget(Token token)
{
    ungetted.push(token); 
}