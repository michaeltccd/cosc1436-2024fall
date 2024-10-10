#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Movie: Title, Actors, Run length, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    //Required
    string Title;

    // At least 0, minutes
    int RunLength;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    EditMovie,
    DeleteMovie,
    ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

/// Displays main menu
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;
}

/// Handles the menu selection
void HandleMenu()
{
    //HACK: Fix this
    MenuCommand menuCommand = (MenuCommand)0;
    switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not implemented" << endl; break;
    };
}

int main()
{
    //Function call ::= id ();    
    DisplayMenu();

    //// Get input
    MenuCommand menuCommand = (MenuCommand)0;
    do 
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //// Handle menu command
    HandleMenu();
    /*switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not implemented" << endl; break;
    };*/

    ////// Add a new movie
    //Create a new movie
    Movie movie;// = {0};

    //Get required title
    do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");

    //Get run length, at least 0, minutes
    do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

    //Get release year, at least 1900
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };

    //Get the optional description
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        cout << "Enter optional genre " << (index + 1) << ": ";

        string genre;
        getline(cin, genre);
        if (genre == "")
            break; //Exits the loop

        movie.Genre += genre + ", ";        
    };

    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}