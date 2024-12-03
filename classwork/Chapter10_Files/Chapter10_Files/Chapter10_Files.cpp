#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void WriteFileDemo()
{
    std::fstream outFile;

    //Open a file for reading and/or writing
    // "C:\\temp\\log.txt"
    // "/usr/temp/log"
    outFile.open("log.txt", std::ios_base::out | std::ios_base::app); //Opening a file for writing, append

    std::string line;
    std::cout << "Enter the file contents: ";

    while (true)
    {
        getline(std::cin, line);
        if (line == "Q" || line == "q")
            break;

        //Write to file
        outFile << line << std::endl;
    };
}

void ReadFileDemo()
{
    std::fstream inFile;

    inFile.open("log.txt", std::ios_base::in); //Opening file for reading

    //While not EOF
    while (!inFile.eof())
    {
        std::string line;
        getline(inFile, line);

        std::cout << line << std::endl;
    };
}

void Display(std::fstream& output, std::string const& message)
{
    output << message;

    std::cout << message;
}

void LogOutputDemo()
{
    //Create log file
    std::fstream logFile;

    logFile.open("output.txt", std::ios_base::out | std::ios_base::app);

    Display(logFile, "Enter your name: \n");
    //std::cout << "Enter your name: ";

    std::string name;
    getline(std::cin, name);

    std::stringstream msg;
    msg << "Hello " << name << std::endl;
    Display(logFile, msg.str());
    //std::cout << "Hello " << name << std::endl;
    //Display(logFile, "Hello ");
    //Display(logFile, name);
    //Display(logFile, "\n");
}

int main()
{
    //ReadFileDemo();
    LogOutputDemo();
}