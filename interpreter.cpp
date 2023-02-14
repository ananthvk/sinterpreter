#include "interpreter.h"
Token Interpreter::get_next_token()
{
        
    int start_pos = current_pos;
    Token next;

    if(!in_bounds())
        return next;

    // Check for end of file
    if (current_pos >= source.length())
    {
        next.type = TOKEN_EOF;
        next.str_value = "";
        return next;
    }

    skip_whitespaces();

    // Check for operators
    if (source[current_pos] == '+' || source[current_pos] == '-' ||
        source[current_pos] == '/' || source[current_pos] == '*')
    {
        next.str_value = source[current_pos];
        next.type = TOKEN_OPERATOR;
        next.value.opval = source[current_pos];
        current_pos++;
        return next;
    }

    // Check for numbers
    while (current_pos < source.size() && std::isdigit(source.at(current_pos)))
        current_pos++;

    if (current_pos != start_pos)
    {
        // We have found a number
        next.str_value = source.substr(start_pos, current_pos - start_pos);
        next.type = TOKEN_INTEGER;
        next.value.ival = std::stoi(next.str_value);

        // If current position is not larger than end of string, we have to

    }

    return next;
}
Token Interpreter::expect(TokenType type)
{
    // What token to expect?
    // If the token which is read has a different type, an error is generated
    Token next = get_next_token();
    //std::cout<<next<<"\n";
    if (next.type != type)
        // TODO: Implement a custom exception class
        throw std::runtime_error("Unexpected token!");
    return next;
}
void Interpreter::expression()
{
    try
    {
        // Looks for the pattern INTEGER OPERATOR INTEGER and gives the result
        Token token;
        int lhs, rhs, result;
        char op;

        token = expect(TOKEN_INTEGER);
        lhs = token.value.ival;

        token = expect(TOKEN_OPERATOR);
        op = token.value.opval;

        token = expect(TOKEN_INTEGER);
        rhs = token.value.ival;

        switch (op)
        {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
        default:
            std::cerr << "Unkown operator " << op << "\n";
            throw std::runtime_error("Unknown operator");
            break;
        }
        std::cout << result << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr <<e.what()<< " - Syntax error!\n";
    }
}
