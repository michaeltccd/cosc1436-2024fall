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
    ///*left = (left * 21) / 21;
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
    if (isClassic == 'Y' || isClassic == 'y')
        movie.IsClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.IsClassic = false;
    else
    {
        cout << "ERROR: You must enter Y or N";

        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;
    };

    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    if (movie.IsClassic)
        cout << "Is Classic? Yes" << endl;
    else
        cout << "Is Classic? No" << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}