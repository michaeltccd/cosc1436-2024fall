#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string GetFilename(const char* message)
{
    std::cout << message;

    std::string filename;
    std::getline(std::cin, filename);

    return filename;
};

void Decrypt(std::fstream& input, std::fstream& output, char key)
{
    //Caesar cipher (additive cipher)    

    //While not end of file
    while (!input.eof())
    {
        char ch;

        //Read next character
        input.get(ch);

        //Resets the error state of a stream
        if (input.fail())
            input.clear();

        //Decrypt it
        ch -= key;

        //Write out
        //output << ch;
        output.put(ch);
    };
};

void Encrypt(std::fstream& input, std::fstream& output, char key)
{
    //Caesar cipher (additive cipher)    

    //While not end of file
    while (!input.eof())
    {
        char ch;

        //Read next character
        input.get(ch);

        //Encrypt it
        ch += key;

        //Write out
        //output << ch;
        output.put(ch);
    };
};

void GetInputFile(std::fstream& input)
{
    do
    {
        std::string inputFilename = GetFilename("Enter input file: ");

        input.open(inputFilename, std::ios_base::in);

        //Error checking functions
        // .fail() -> true if failed otherwise false for last file operation
        // .bad() -> true if failed otherwise false for last file operation
        // .good() -> true if last file operation succeeded or false otherwise
        //if (!input.fail())
        //if (input.good())
        if (input.is_open())
            return;
        
        std::cout << "Error opening file" << std::endl;
    } while (true);
};

void GetOutputFile(std::fstream& output)
{
    do
    {
        std::string filename = GetFilename("Enter output file: ");

        output.open(filename, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

        //Error checking functions
        // .fail() -> true if failed otherwise false for last file operation
        // .bad() -> true if failed otherwise false for last file operation
        // .good() -> true if last file operation succeeded or false otherwise
        //if (!input.fail())
        //if (input.good())
        if (output.is_open())
            return;

        std::cout << "Error opening file" << std::endl;
    } while (true);
};

enum Direction
{
    EncryptMode,
    DecryptMode
};

Direction GetDirection()
{
    std::cout << "(E)ncrypt or (D)ecrypt? ";

    do
    {
        char ch;
        std::cin >> ch;
        switch (ch)
        {
            case 'E':
            case 'e': return Direction::EncryptMode;

            case 'D':
            case 'd': return Direction::DecryptMode;
        };

        std::cout << "Bad input" << std::endl;
    } while (true);
};

int main()
{    
    //Open input file for reading, output file for writing
    std::fstream inputFile;
    GetInputFile(inputFile);

    //Open output file    
    std::fstream outputFile;
    GetOutputFile(outputFile);    

    Direction mode = GetDirection();
    switch (mode)
    {
        case Direction::EncryptMode: Encrypt(inputFile, outputFile, 56); break;
        case Direction::DecryptMode: Decrypt(inputFile, outputFile, 56); break;
    };    
}