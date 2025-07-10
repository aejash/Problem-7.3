/**** Problem 7.3 - Chapter 7, Project A
*---------------------------------------------
***** Write a program that reads lines of text and appends them to a char buffer[1000].
***** Read one character at a time by calling cin.get(ch), where ch is a variable of type char.
***** Use input redirection (Special Topic 4.9).
***** Stop after reading 1,000 characters.
***** As you read in the text, replace all newline characters '\n' with '\0' terminators.
***** Establish an array char* lines[100], so that the pointers in that array point to the
***** beginnings of the lines in the text. Consider only 100 input lines if the input
***** has more lines. Then display the lines in reverse order, starting with the last input line. */

// Programmer - Ashley Jacobson
// Tester - Heily Cabrera Guerrero
// Group Project A //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    char buffer[1000];    // Char Array
    char ch;
    char* lines[100] = {};  // Pointer array for lines of characters
    char previous;
    int lineCounter = 0;   // Keeps tracks of how many lines there are

    /******* Reads input using input redirection *******/

    streambuf *cinBuffer = cin.rdbuf();
    ifstream file("input.txt");
    cin.rdbuf(file.rdbuf());



    /******* Reads characters into character buffer array *******/

    int count = 0;   // Keeps track of how many characters are in the array
    while (cin.get(ch) || count < 1000)
    {
        buffer[count] = ch;
        if(buffer[count] == '\n')
        {
            buffer[count] = '\0';    // Sets the new line to '\0'
        }
        count++;
    }
    /******* Copy Lines into Pointer Array (lines) *******/

    int charTracker = 0; // Counts characters in a specific line
    int count2 = 0; // Newly established character counter used to track the index of where
                    // the line should start
    for (int i = 0; i < count; i++)
    {
        if (previous == '\0')
        {

            lines[lineCounter] = &buffer[count2 - charTracker]; // Copies the line to the line array by
                                                               //calculating the difference between
                                                               //where the line starts and ends
            charTracker = 0;
            lineCounter++;
        }
        previous = buffer[i];
        count2++;
        charTracker++;
    }

    /******* Prints line array in reverse order *******/

    for(int j = lineCounter; j >= 0; j--)
    {
        if(lines[j])
        {
            cout << lines[j];

        }
        cout << endl;
    }
        cin.rdbuf(cinBuffer);

    return 0;
}
