#include "token.h"
#include<string>
#include<iostream>

class Interpreter{
    private:
        std::string source;
        int current_pos;
        bool in_bounds(){
            if(current_pos >= source.size())
                return false;
        }
    public:
        Interpreter(const std::string& source):source(source), current_pos(0) {
        }
        Token get_next_token(){
            int start_pos = current_pos;
            Token next;

            // Check for end of file
            if(current_pos >= source.length()){
                next.type = TOKEN_EOF;
                next.str_value = "";
                return next;
            }

            // Check for operators
            if(source[current_pos] == '+'){
                next.str_value = "+";
                next.type = TOKEN_OPERATOR;
                next.value.opval = '+';
                return next;
            }

            // Check for numbers
            while(current_pos < source.size() && std::isdigit(source.at(current_pos)))
                current_pos++;
            
            if(current_pos != start_pos){
                // We have found a number
                next.str_value = source.substr(start_pos, current_pos-start_pos);
                next.type = TOKEN_INTEGER;
                next.value.ival = std::stoi(next.str_value);

                // If current position is not larger than end of string, we have to decrement current_pos
                // since an extra character has been processed
                if(current_pos < source.size())
                    current_pos--;
                return next;
            }

        }
        int expression()
        {
            // Looks for the pattern INTEGER OPERATOR INTEGER and gives the result
        }
};

