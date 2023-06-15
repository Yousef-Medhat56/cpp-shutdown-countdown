#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;

void printHeader();                  // print the program header in the terminal
int readPositiveInt(string message); // read a positive integer from the user
void printErrorMsg(string error);    // print error message

int main()
{
    int minutes_to_shutdown;
    int seconds_to_shutdown;

    printHeader();

    minutes_to_shutdown = readPositiveInt("- How many minutes to shutdown the pc: ");
    seconds_to_shutdown = minutes_to_shutdown * 60;

    while (seconds_to_shutdown > 0)
    {
        // if there is more than 1 minute until shutdown
        if (seconds_to_shutdown > 60)
        {
            cout << "The pc will shutdown after " << seconds_to_shutdown / 60 << " minutes" << endl;
            Sleep(60000); // sleep for 60 seconds
            seconds_to_shutdown -= 60;
        }
        else
        {
            cout << "The pc will shutdown after " << seconds_to_shutdown << " seconds" << endl;
            Sleep(1000); // sleep for 1 second
            seconds_to_shutdown--;
        }

        system("cls");
        printHeader();
    }

    system("C:\\Windows\\System32\\shutdown /s");
    return 0;
}

void printHeader()
{
    cout << "==================================\n";
    cout << "\tShutdown countdown\t" << endl;
    cout << "==================================\n\n";
}

int readPositiveInt(string message)
{
    int input;
    // check that the input is integer
    while (cout << message && !(cin >> input))
    {
        printErrorMsg("Please enter a valid input");
        cin.clear();                                                   // clear bad input flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
    }

    // check that the integer is not negative
    if (input >= 0)
        return input;
    else
    {
        printErrorMsg("The input can't be negative");
        return readPositiveInt(message);
    }
}

void printErrorMsg(string error)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // change text color to red
    cout << error << endl;
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}
