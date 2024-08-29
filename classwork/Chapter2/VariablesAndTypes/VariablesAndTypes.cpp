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
    
    // Literals - constant value expression
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
    //   Expression - can be used anywhere an expression is allowed
    //   Styling - Name: nouns, Casing: Camel
    // 
    // variable-decl ::= T id [ '=' E ] { ',' id [ '=' E ] }* ';'
    int length;
    length = 0;  
    //int length = 0; //Preferred

    int releaseYear = 1900;    
    int rating = 3, stars = 5;
    
    std::cout << length;

    //Identifiers
    //int _hours, _1stGrade, 1stGrade, first-grade;
    int examGrade, hoursWorked;
    //int exam_grade, hours_worked; DONT DO THIS
    //std::cout << e

    // Types
    //   Defines what kind of data is stored, range, size
    //   Primitives - understood by lang
    // | Type | Size | Range |
    // |- | - | - |
    // | short | 2 | +-32767 (integral) |
    // | int | 4 | +- 2 billion (default) |
    // | long | 4 | +-2 billion |
    // | unsigned * | * | 0-
    // Floats
    // | float | 4 | E+-38 | precision: 5-7 |
    // | double | 8 | E+-308 | precision: 12-15 (default) |
    // Text
    // | char | 1 | -128 to 127 | character |
    // | std::string | * | text |
    // | bool | 1? | true or false |
    short s;
    int i = 0;
    long l = 5L;
    unsigned int ui = 3U;
    float pi = 3.14159F;
    double largeNumber = 10E100;
    char c = 'A';
    std::string name = "Bob";
    bool isPassing = true;
    //int isOK = 1; //Don't do it
    int intSize = sizeof(int);

    //Assignment
    //  asn_op ::= V = E
    //  Must be type compatible
    //  Expression of type Vt
    //  Associativity - Right
    int shapeLength = 10;
    int shapeWidth = 20;
    int shapeArea;

    shapeArea = shapeLength;
    shapeWidth = 10;
    //20 = shapeWidth;

    shapeArea = shapeLength = shapeWidth = 20;

    //Arithmetic operators
    // + - * / % (int modulus)
    //  arith_op ::= Et op Et
    //   Modulus only defined for integer values
    //   Division for integers returns integers
    shapeArea = shapeLength * shapeWidth;
    int remainder = 10 % 3; // 1
    int result = 10 / 3;  // 3
    double dresult = 10.0 / 3.0;  // 3.333

    // unary_op ::= + Et | - Et
    //   Unary positive does nothing
    //   Unary negative negates the expression
    int positiveValue = 10;
    int negativeValue = -positiveValue;

    // block-statement ::= { S* }
    //   Variables declared in block are scoped to the block
    //   Useful for grouping statements
    {
        int newVariable = 10;
    }
    //std::cout << newVariable;
}