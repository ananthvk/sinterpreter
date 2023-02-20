# S mathematical interpreter
This is a small on going project of mine to understand how interpreters, parsing and compilers work.
I am following tutorials from [https://ruslanspivak.com/lsbasi-part1/](https://ruslanspivak.com/lsbasi-part1/) and
[https://craftinginterpreters.com/contents.html](https://craftinginterpreters.com/contents.html).

# Specification

I have implemented the token using a tagged union data structure, currently supporting 5 datatypes - int, char, double, bool
and string. The implementation to process integers is complete.
Here is a list of files and a brief gist of what it contains.

`token.h` - Contains the definition for `Token`, `TokenType`, methods to get a string representation of a token, etc.  `token.c` contains the implementation for the above header file.

`lexer.h` and `lexer.cpp` contains the implementation for the lexer, get the next token by calling `next()`.  Currently stores the entire source in memory and uses a index for the position of the next token.

`interpreter.h` and `interpreter.cpp` has the definition and implementation for the parser and the interpreter.  This project uses a recursive descent parser for parsing and contains various methods which give the non terminals of the language.

`test.py` and `test_random.py` performs some tests on the interpreter by validating the result with the result of Python's `eval()` function.

# TODO
1. Extend this interpreter to handle floats, and larger integers.
2. Learn and implement ASTs instead of direct calculations.
3. Develop this interpreter to a full fledged language.
4. Handle undefined behaviour due to integer overflows/underflows(currently caught by asan).
5. Better syntax error reporting.