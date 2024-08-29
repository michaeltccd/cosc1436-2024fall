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

    //File paths
    std::cout << "C:\\windows\\temp";
    //std::cout << R"C:\windows\temp";

    // Variables
    //   Named memory location to store data    
    //   Declaration - tell compiler a variable exists
    //   Scope - lifetime of a variable/identifier: Point of declaration to end of block
    // 
    // variable-decl ::= T id [ '=' E ] { ',' id [ '=' E ] }* ';'
    int length;
    length = 0;

    int releaseYear = 1900;    
    int rating = 3, stars = 5;

    std::cout << length;
}