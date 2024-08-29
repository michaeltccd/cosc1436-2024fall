#include <iostream>

//Entry point
int main()
{    
    // cout << E
    // std::endl ::= new line, only works with cout
    //Output a message - 1
    std::cout << "Hello World" << std::endl;

    //Message - 2
    std::cout << "Hello" << " " << "World" << std::endl;

    //Message - 3
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World";
    std::cout << std::endl;

    //Message - 4
    std::cout << "Hello\tWorld\n";

    std::cout << "Hello \"Bob\"";
    
    // String literals - double quote encased
    //    Escape sequence - special meaning to compiler, starts with a \, only works in literals
    //        \n = newline
    //        \t = tab
    //        \\ = \
    //        \" = "
    //File paths are the most painful
    std::cout << "C:\\windows\\temp";    

    // Variables
    //   Named memory location to store data    
    //   Declaration - tell compiler a variable exists
    //   Scope - lifetime of a variable/identifier: Point of declaration to end of block
    // 
    // variable-decl ::= T id [ '=' E ] { ',' id [ '=' E ] }* ';'
    int length;
    length = 0;  
    //int length = 0; //Preferred

    int releaseYear = 1900;    
    int rating = 3, stars = 5;

    std::cout << length;
}