#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

int readPositiveInt(string message); // read a positive integer from the user

int main()
{
    int minutes_to_shutdown;
    int seconds_to_shutdown;

    minutes_to_shutdown = readPositiveInt("- How many minutes to shutdown the pc: ");
    seconds_to_shutdown = minutes_to_shutdown * 60;

    while (seconds_to_shutdown > 0)
    {
        // if there is more than 1 minute until shutdown
        if (seconds_to_shutdown > 60)
        {
            cout << "The pc will shutdown after " << seconds_to_shutdown / 60 << " minutes" << endl;
            this_thread::sleep_for(chrono::seconds(60)); // sleep for 60 seconds
            seconds_to_shutdown -= 60;
        }
        else
        {
            cout << "The pc will shutdown after " << seconds_to_shutdown << " seconds" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // sleep for 1 second
            seconds_to_shutdown--;
        }

        system("cls");
    }

    // system("C:\\Windows\\System32\\shutdown /s");
    return 0;
}

int readPositiveInt(string message)
{
    int input;
    // check that the input is integer
    while (cout << message && !(cin >> input))
    {
        cin.clear();                                                   // clear bad input flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
    }

    // check that the integer is not negative
    if (input >= 0)
        return input;
    else
    {
        return readPositiveInt(message);
    }
}
