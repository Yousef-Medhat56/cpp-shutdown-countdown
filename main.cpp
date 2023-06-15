#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int minutes_to_shutdown;
    int seconds_to_shutdown;

    cout << "How many minutes to shutdown the pc: ";
    cin >> minutes_to_shutdown;

    seconds_to_shutdown = minutes_to_shutdown * 60;
    
    for (int i = seconds_to_shutdown; i > 0; i--)
    {
        cout << "The pc will shutdown after " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    system("C:\\Windows\\System32\\shutdown /s");
    return 0;
}