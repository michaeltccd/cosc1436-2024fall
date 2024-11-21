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

// "C" strings - 
// C++ strings only work in C++
// #include <cstring>
//   strlen(const char*) size_t ::= returns number of characters
void CStringDemo()
{
    const char* name = "Bob"; //const char*
    char nameArray[] = "Bob";

    const int MaximumName = 101;
    char buffer[MaximumName] = {0};

    // String length (in chars)
    //   strlen(const char*) size_t
    /*std::cout << "Enter first name: ";
    std::cin >> buffer;

    int len = strlen(buffer);
    buffer[len++] = ' ';    

    std::cout << "Enter last name: ";
    std::cin >> &buffer[len];
    
    std::cout << buffer << std::endl;
    */

    char firstName[MaximumName] = {0};
    std::cout << "Enter first name: ";
    std::cin >> firstName;

    char lastName[MaximumName] = {0};
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    char fullName[MaximumName + MaximumName] = {0};

    //Copy and concat
    //   strcpy(char*, const char*)
    //   strncpy(char*, const char*, int length)
    //   strcat(char*, const char*)
    //   strncat(char*, const char*, int length)
    //strcpy(fullName, firstName);
    strncpy_s(fullName, firstName, MaximumName);
    strcat_s(fullName, " ");
    strncat_s(fullName, lastName, MaximumName);

    std::cout << fullName << std::endl;

    //Comparison
    //  strcmp(const char*, const char*) int
    //  _stricmp(const char*, const char*) int
    //if (firstName == lastName)
    if (_stricmp(firstName, lastName) == 0)
        std::cout << lastName << std::endl;
    else
        std::cout << fullName << std::endl;

    //Find in string - returns pointer to start of second string in first, or nullptr
    // strstr (const char*, const char*) const char*
    // strstr (char*, const char*) char*
    char productName[] = "Microsoft Windows 11";
    char operatingSystem[] = "Windows";

    char* pPos = strstr(productName, operatingSystem);
    if (pPos != nullptr)
        std::cout << pPos << std::endl;
}

void NumberStringDemo()
{
    while (true)
    {
        char buffer[100] = {0};

        std::cout << "Enter a number: ";
        std::cin >> buffer;

        // Conversion
        //    #include <cstdlib>
        //    atoi(const char*) int :: Converts string to int, or 0
        //    atol(const char*) long :: converts string to long, or 0
        //    atof(const char*) double :: Converts string to double
        //bool isNumber = IsIntegral()
        int value = atoi(buffer);
        std::cout << "Value as int = " << value << std::endl;
    };
}

void CPlusPlusStringDemo()
{    
    //char firstName[MaximumName] = {0};
    std::string firstName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;

    //char lastName[MaximumName] = {0};
    std::string lastName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    //char fullName[MaximumName + MaximumName] = {0};
    std::string fullName;

    // String copy/assign string value ::= use assignment operator
    fullName = firstName;
    //strncpy_s(fullName, firstName, MaximumName);

    // String concat ::= Use addition operator
    //                  | .append(const char*)
    fullName += " ";
    //strcat_s(fullName, " ");
    
    //fullName += lastName;
    fullName.append(lastName);
    //strncat_s(fullName, lastName, MaximumName);

    std::string middleName;
    std::cout << "Enter middle name: ";
    std::cin >> middleName;

    // Find a string in a string ::= .find(const char*, [index]) int, returns index of value, if any
    // Insert a string ::= .insert(index, const char*) 
    //Insert middle name
    int index = fullName.find(" ");  //strstr
    fullName.insert(index, middleName);   //strcat(str+index)

    std::cout << fullName << std::endl;

    // Get subsstring ::= .substr(index, [count]) std::string, returns substring starting at index
    //Get last name
    std::string onlyLastName = fullName.substr(index + 1);

    //Misc
    //   .c_str() const char*, returns pointer to C-string, not stable or writable
    //   .length() size_t, returns # of characters in string
    //   .empty() bool, returns if the string is empty
    //   .clear() void, clears the string
    const char* pCString = fullName.c_str();  //Get pointer to underlying buffer
    int len = fullName.length();              //Length, in characters
    bool isEmpty = fullName.empty();  //Is there a string?
    fullName.clear();                         //Empties the string
    //fullName = "";

}

int main()
{    
    //CharDemo();
    //WideCharDemo();
    //StringDemo();
    //CStringDemo();
    NumberStringDemo();
}