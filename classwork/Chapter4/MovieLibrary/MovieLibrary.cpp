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
};

//Integral data type with named values
enum MenuCommand
{
    MC_AddMovie,
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie
};

int main()
{
    //Relational demo
    // rel_op ::= < <= > >= == !=
    // rel_expr ::= E rel_op E (boolean)

    ////int left, right;
    //string left, right;
    //std::cout << "Enter a left and right value: ";
    //std::cin >> left >> right;

    ////Mangle the values
    //// Do not use == equality floating point values to avoid rounding errors
    //// Except when comparing floating point value to an integral (e.g. f == 45)
    ////left = (left * 21) / 21;
    //right = (right * 15) / 15;*/
    //
    ////bool areEqual = left = right == 20;
    ////bool areEqual = left = 20 = right;

    ////String comparison for case insensitive
    //// strcmpi(string, string) => int
    ////    when using C++ strings specify value as `expr`.c_str()
    ////    returns < 0 if left < right
    ////            = 0 if left == right
    ////            > 0 if left > right
    //cout << left << " ciequal " << right << " = " << _strcmpi(left.c_str(), right.c_str()) << endl;
    //cout << left << " == " << right << " = " << (left == right) << endl;
    //cout << left << " < " << right << " = " << (left < right) << endl;
    //cout << left << " <= " << right << " = " << (left <= right) << endl;
    //cout << left << " > " << right << " = " << (left > right) << endl;
    //cout << left << " >= " << right << " = " << (left >= right) << endl;    
    //cout << left << " != " << right << " = " << (left != right) << endl;
    //cout << endl;

    //// Show menu
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    //// Get input
    char input;
    cin >> input;

    MenuCommand menuCommand;

    switch (input)
    {
        case 'A':
        case 'a': menuCommand = 1; break;

        case 'E':
        case 'e': menuCommand = 2; break;

        case 'D':
        case 'd': menuCommand = 3; break;

        case 'V':
        case 'v': menuCommand = 4; break;

        default: cout << "Bad input" << endl; break;
    };

    //// Handle menu command
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie:
        case MenuCommand::MC_EditMovie:
        case MenuCommand::MC_DeleteMovie:
        case MenuCommand::MC_ViewMovie: cout << "Not implemented" << endl; break;
    };

    ////// Add a new movie
    //Create a new movie
    Movie movie;// = {0};

    //Get required title
    cout << "Enter a title: ";
    //cin >> movie.Title;
    getline(cin, movie.Title);

    //Decision making - IF statement
    // if-stmt ::= if (Eb) S ;
    if (movie.Title == "")
    {
        cout << "ERROR: Title is required" << endl;

        cout << "Enter a title: ";
        getline(cin, movie.Title);
    };

    //Get run length, at least 0, minutes
    cout << "Enter run length (in minutes): ";
    cin >> movie.RunLength;
    
    //Nested if
    //if (movie.RunLength <= 0)
    //{
    //    //Look at additional stuff...
    //    
    //    if (movie.RunLength < 0)
    //    {
    //        cout << "ERROR: Run length must be at least 0" << endl;

    //        cout << "Enter run length (in minutes): ";
    //        cin >> movie.RunLength;
    //    };
    //} else if (movie.RunLength > 1440)
    //{
    //    cout << "ERROR: Run length cannot be greater than a day" << endl;

    //    cout << "Enter run length (in minutes): ";
    //    cin >> movie.RunLength;
    //};
    if (movie.RunLength < 0 || movie.RunLength > 1440)
    {
        cout << "ERROR: Run length must be between 0 and 1440" << endl;

        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;
    };

    //Get release year, at least 1900
    cout << "Enter release year (1900+): ";
    cin >> movie.ReleaseYear;

    if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "ERROR: Release year must be between 1900 and 2100" << endl;

        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;
    };

    //Get the optional description
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    char isClassic;
    cout << "Is this a classic (Y/N)? ";
    cin >> isClassic;

    /*if (isClassic == 'Y')
        movie.IsClassic = true;
    else if (isClassic == 'y')
        movie.IsClassic = true;
    else if (isClassic == 'N')
        movie.IsClassic = false;
    else if (isClassic == 'n')
        movie.IsClassic = false;*/
    /*if (isClassic == 'Y' || isClassic == 'y')
        movie.IsClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.IsClassic = false;
    else
    {
        cout << "ERROR: You must enter Y or N";

        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;
    };*/

    //Switch (select) statement - replacement for if-elseif where same expression compared to multiple values
    // 1. Must compare a single expression to one or more constant values with equality
    // 2. Switch expression must be an integral type
    // 3. Each case label must be a compile-time constant expression
    // 4. Each case label must be unique
    switch (isClassic)
    {
        case 'Y': 
        case 'y': movie.IsClassic = true; break;
            
        case 'N': 
        case 'n': movie.IsClassic = false; break;

        default:
        {
            cout << "ERROR: You must enter Y or N";

            cout << "Is this a classic (Y/N)? ";
            cin >> isClassic;
        };
    };       
    
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    // Long form - 1
    //if (movie.IsClassic)
    //    cout << "Is Classic? Yes" << endl;
    //else
    //    cout << "Is Classic? No" << endl;
    // Better but longer form - 2
    /*string classicIndicator;
    if (movie.IsClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";
    cout << "Is Classic? " << classicIndicator << endl;*/

    //Shorter form using conditional operator => Eb ? Et : Ef    
    //string classicIndicator = movie.IsClassic ? "Yes" : "No";
    //cout << "Is Classic? " << classicIndicator << endl;
    
    //Shortest form using conditional operator => Eb ? Et : Ef  
    // Et & Ef = must be the exact same type, type coercion is not allowed  
    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}