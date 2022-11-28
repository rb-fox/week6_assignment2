// program name goes here
// your name goes here
// any example usage or helpful command line arguments go here

#include <iostream>
// Add any other header files here
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

// This function takes a char to print and a message and prints a nice introduction 
// surrounded by the characters char. See pic in assignment.
void Introduction(char c, string message)
{
    //Display header
    cout << setfill(c) << setw(40) << c << endl;
    cout << setfill(c) << setw(2) << c << message << setfill(c) << setw(2) << c << endl;
    cout << setfill(c) << setw(40) << c << endl;
    cout << endl;

    //Display output to the user
    cout << "Enter \'c\' to invoke \'GetCountOfTeam()\'" << endl;
    cout << "Enter \'w\' to invoke \'GetMostWinningTeam()\'" << endl;
    cout << "Enter \'d\' to invoke \'GetTeamForDate()\'" << endl;
    cout << "Enter \'v\' to invoke \'ConvertTeamNameCase()\'" << endl;
    cout << "Enter \'x\' to exit the program" << endl;

}

// This function takes a file name and reads in data, storing it in a string array that is used 
// by the rest of the program. Use this function to read the team names or the corresponding dates. 
// The function should return true on success or false on failure.
bool ReadFile(string fileName, string data[], const int maxArraySize)
{
    //Declare variables
    ifstream inFile;
    int index = 0;
    bool result = false;

    // Open text file
    inFile.open(fileName);

    if (!inFile)
    {
        cout << "Cannot open input file. " << "Program exiting. " << endl;
    }

    else 
    {
        for (index = 0; index < maxArraySize; index++)
        {
        getline(inFile, data[index]);
        }

        result = true;

        inFile.close();
    }        

    return(result);
}

// This function gets the number of occurrences of a team name in the array of teams 
// and returns the count of the teams as a constant integer.
const int GetCountOfTeam(string teamName, const string teams[], const int maxArraySize)
{
    //Declare variables
    int index = 0;
    int count = 0;

    for (index = 0; index < maxArraySize; index++)
    {
        if (teamName == teams[index])
            count = count + 1;

    }

    return(count);
}

// This function searches the team's array for the team's name that won the world series 
// the most times and returns it as a constant string.
const string GetMostWinningTeam(const string teams[], const int maxArraySize)
{
    //Declare variables
    int index = 0;
    int searchIndex = 0;
    int count = 0;
    int maxCount = 0;
    string mostWinningTeam;

    for (index = 0; index < maxArraySize; index++)
    {
        count = 0;

        for (searchIndex = 0; searchIndex < maxArraySize; searchIndex++)
        {
            if (teams[index] == teams[searchIndex])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mostWinningTeam = teams[index];
        }
    }

    return(mostWinningTeam);
}

// This function returns the team that won the world series on the "date".
const string GetTeamForDate(const string date, const string teams[], const string dates[], const int maxArraySize)
{
    //Declare variables
    int index = 0;
    string team = " ";

    for (index = 0; index < maxArraySize; index++)
    {
        dates[index];

        if (date == dates[index])
            team = teams[index];
    }

    return(team);
}

// This function changes all of the team names to either upper or lower case depending on the value of "to_upper".
 void ConvertTeamNameCase(bool to_upper, string teams[], const int maxArraySize)
{

     if (to_upper == true)
     {
         for (int i = 0; i < maxArraySize; i++)
         {
             transform(teams[i].begin(), teams[i].end(), teams[i].begin(), ::toupper);

         }
         cout << "The case for all teams has been changed to \'upper\'." << endl;
     }
     else
     {
         for (int i = 0; i < maxArraySize; i++)
         {
             transform(teams[i].begin(), teams[i].end(), teams[i].begin(), ::tolower);

         }
         cout << "The case for all teams has been changed to \'lower\'." << endl;
     }
     

}

// This function provides the menu and calls the other functions according to what the user inputs. 
// See pic in assignment for more details.
int main(int argc, char* argv[])
{
    
	if (argc < 3)
	{
		cout << "Error! Not enough file names. Expecting 2!" << endl;
		return -1;
	}

    // Const representing the number of lines of data in both files.
	const int SIZE_DATA = 120;

    //Declare variables
    ifstream inFile;
    int index = 0;
    int count = 0;
    string teamWon = " ";
    string team = " ";
    string teams[SIZE_DATA];
    string dates[SIZE_DATA];
    string teamName;
    string date = " ";
    string message = " Welcome to my World Series Program "; 
    string fileName = " ";
    bool fileOnePassed = false;
    bool fileTwoPassed = false;
    bool to_upper = false;
    char c = '*';
    char operation = ' ';
    char choice = ' ';


    // Function that takes a char to print and a message and prints an introduction
    Introduction('*', message);

    // Function that takes a file name and reads in data and returns true on success or false on failure.
    fileOnePassed = ReadFile(argv[1], teams, SIZE_DATA);

    if (fileOnePassed == true)
    {
        // Function that takes a file name and reads in data and returns true on success or false on failure.
        fileTwoPassed = ReadFile(argv[2], dates, SIZE_DATA);
    }

    else
    {
        return(-1);
    }

    if (fileTwoPassed == true)
    {

        //Decide which function to call
        while (operation != 'x' && operation != 'X')
        {

            // Add space for next prompt
            cout << endl;
            cout << endl;

            //Receive users input
            cout << "Please enter an operation to perform:";
            cin >> operation;

            if (operation == 'c' || operation == 'C')
            {
                //User input name
                cout << "Please enter the team name:";
                //Clear buffer
                cin.ignore();
                // Read user input with white spaces
                getline(cin, teamName);

                // Function that gets the number of occurrences of a team name in the array of teams and returns the count as a constant integer.
                count = GetCountOfTeam(teamName, teams, SIZE_DATA);

                cout << "The number of times the \'" << teamName << "\' won the world series is \'" << count << "\'.";
            }

            else if (operation == 'w' || operation == 'W')
            {
                // Function that searches the team's array for the team's name that won the world series the most times and returns it as a constant string.
                const string mostWinning = GetMostWinningTeam(teams, SIZE_DATA);

                cout << "The most winning team is \'" << mostWinning << "\'." << endl;
            }

            else if (operation == 'd' || operation == 'D')
            {
                cout << "Please enter the date:";
                cin >> date;

                // Function that returns the team that won the world series on that date.
                teamWon = GetTeamForDate(date, teams, dates, SIZE_DATA);

                cout << "The team that won the world series on \'" << date << "\' is \'" << teamWon << "\'.";
            }

            else if (operation == 'v' || operation == 'V')
            {
                cout << "Please enter the case to change (\'u\' = upper and \'l\' = lower):";
                cin >> choice;

                if (choice == 'u' || choice == 'U')
                {
                    to_upper = true;
                }
                else
                {
                    to_upper = false;
                }
      
                // Function that changes all of the team names to either upper or lower case.
                ConvertTeamNameCase(to_upper, teams, SIZE_DATA);
            }

            else if (operation == 'x' || operation == 'X')
            {
                //Displays out to user when exiting
                cout << "Good bye." << endl;
            }
            else
            {
                cout << "Invalid selection please choose \'c\', \'w\', \'d\', \'v\', or \'x\'. Try again." << endl;
            }
        }

        // Return 0 to indicate success.
        return (0);
    }

    else
    {
        return(-1);
    }
}
