#include "interpreter.h"
#include "lexer.h"
#include <iostream>
int main()
{
    std::string line;
    //std::cout << "Sinterpreter - type 'exit' to quit\n";
    while (std::getline(std::cin, line))
    {
        if (line == "exit")
            break;
        // If line is emtpy, continue so that line.front() does not cause a UB
        if(line.empty())
            continue;
        // To handle single comments
        if (line.front() == '#')
            continue;
        try
        {
            Lexer lexer(line);
            Interpreter interpreter(lexer);
            std::cout << interpreter.expression() << "\n";
        }
        catch (std::runtime_error &e)
        {
            std::cout << "Syntax error:" << e.what() << "\n";
        }
        catch (std::logic_error &e)
        {
            std::cout << "Internal error:" << e.what() << "\n";
            std::terminate();
        }
        catch (std::exception &e)
        {
            std::cout << "System error:" << e.what() << "\n";
        }
        //std::cout << ">>";
    }
}