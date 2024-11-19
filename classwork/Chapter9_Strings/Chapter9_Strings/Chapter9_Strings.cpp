#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>  //Char type functions from C

//Character sets - maps numeric values to characters
//  ASCII (7-bit) 0-127 (char)
//  ANSI (1 byte) 0-255 (char)
//  MBCS (1-4 bytes, multi-byte character set) - for localization (char)
//    Each byte has to be examined to determine if subsequent bytes are needed for full char
//  Unicode (2 bytes, Windows, or 4 bytes) - all languages in world (wchar_t)

bool IsIdentifier(char input)
{
    return isalnum(input) || input == '_';
};

bool IsIntegral(std::string const& value)
{
    //for (int index = 0; index < value.length(); ++index)
    for (char ch : value)
        if (!isdigit(ch))
            return false;

    return true;
};

bool IsValidIdentifier(std::string const& value)
{
    for (char ch: value)
        if (!isalnum(ch) && ch != '_')
            return false;

    return true;
};

void StringDemo()
{
    while (true)
    {
        std::string input;
        std::cout << "Enter a value: ";
        std::getline(std::cin, input);

        std::cout << "Integer = " << IsIntegral(input) << std::endl;
        std::cout << "Identifier = " << IsValidIdentifier(input) << std::endl;
    };
}

void CharDemo()
{
    while (true)
    {
        char input;
        std::cout << "Enter a character: ";
        std::cin >> input;
        
        //Classification ::= int func ( int )        
        // 
        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        std::cout << "Alpha = " << (isalpha(input) ? 'Y' : 'N') << std::endl;  //Letter
        std::cout << "Digit = " << (isdigit(input) ? 'Y' : 'N') << std::endl;  //Digit
        std::cout << "Letter/Digit = " << (isalnum(input) ? 'Y' : 'N') << std::endl;  //Letter or digit
        std::cout << "Lower = " << (islower(input) ? 'Y' : 'N') << std::endl;  //Lower case letter
        std::cout << "Upper = " << (isupper(input) ? 'Y' : 'N') << std::endl;  //Upper case letter
        std::cout << "Space = " << (isspace(input) ? 'Y' : 'N') << std::endl;  //Space
        std::cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << std::endl;  //Space

        //Conversion ::= int func ( int )
        std::cout << "Lower = " << tolower(input) << std::endl;  //Convert to lower case
        std::cout << "Upper = " << toupper(input) << std::endl;  //Convert to upper case
    };
}

void WideCharDemo()
{
    while (true)
    {
        wchar_t input;
        std::cout << "Enter a character: ";
        std::wcin >> input;

        //Classification ::= int func ( int )        
        // 
        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        std::cout << "Alpha = " << (iswalpha(input) ? 'Y' : 'N') << std::endl;  //Letter
        std::cout << "Digit = " << (iswdigit(input) ? 'Y' : 'N') << std::endl;  //Digit
        std::cout << "Letter/Digit = " << (iswalnum(input) ? 'Y' : 'N') << std::endl;  //Letter or digit
        std::cout << "Lower = " << (iswlower(input) ? 'Y' : 'N') << std::endl;  //Lower case letter
        std::cout << "Upper = " << (iswupper(input) ? 'Y' : 'N') << std::endl;  //Upper case letter
        std::cout << "Space = " << (iswspace(input) ? 'Y' : 'N') << std::endl;  //Space
        //std::cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << std::endl;  //Space

        //Conversion ::= int func ( int )
        std::cout << "Lower = " << towlower(input) << std::endl;  //Convert to lower case
        std::cout << "Upper = " << towupper(input) << std::endl;  //Convert to upper case
    };
}

int main()
{    
    //CharDemo();
    WideCharDemo();
    //StringDemo();
}