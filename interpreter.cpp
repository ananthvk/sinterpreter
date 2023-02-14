#include "interpreter.h"
Token Interpreter::get_next_token()
{

    int start_pos = current_pos;
    Token next;

    if (!in_bounds())
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
    // std::cout<<next<<"\n";
    if (next.type != type)
        // TODO: Implement a custom exception class
        throw std::runtime_error("Unexpected token!");
    return next;
}
int Interpreter::compute(int lhs, int rhs, Token op)
{

    int result;

    switch (op.value.opval)
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
    return result;
}
int Interpreter::expression()
{
    // Looks for the pattern INTEGER OPERATOR INTEGER and gives the result
    // To handle expressions such as 3 + 2 - 4 + 5, etc
    // Start solving from the left
    // 3+2 ===> 5
    // 5 + 2 - 4 + 5
    // 5 + 2 ===> 7
    // 7 - 4 + 5
    // And so on

    // To do this, set the value of result to lhs after the first sequence
    // is found
    Token token, op;
    int rhs, result = 0;

    token = expect(TOKEN_INTEGER);
    result = token.value.ival;

    while (token.type != TOKEN_EOF)
    {
        if (!in_bounds())
            break;
        op = expect(TOKEN_OPERATOR);
        token = expect(TOKEN_INTEGER);
        rhs = token.value.ival;
        result = compute(result, rhs, op);
    }
    return result;
}
