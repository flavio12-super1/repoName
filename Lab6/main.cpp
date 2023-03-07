#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

bool getTimeFromUser(Time &timeStruct);
void print24Hour(Time timeStruct);

int main()
{
    Time startTime, endTime;

    cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
    bool validStartTime = getTimeFromUser(startTime);
    if (!validStartTime)
    {
        cout << "The start time entered is invalid!" << endl;
        return 0;
    }

    cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
    bool validEndTime = getTimeFromUser(endTime);
    if (!validEndTime)
    {
        cout << "The end time entered is invalid!" << endl;
        return 0;
    }

    cout << "The lecture starts at ";
    print24Hour(startTime);
    cout << " and ends at ";
    print24Hour(endTime);
    cout << endl;

    return 0;
}

bool getTimeFromUser(Time &timeStruct)
{
    string timeStr;
    getline(cin, timeStr);

    // Check if the string contains the right characters
    if (timeStr.size() != 8 || timeStr[2] != ':' || timeStr[5] != ':')
    {
        return false;
    }

    // Extract the numbers and convert to integers
    int hour = atoi(timeStr.substr(0, 2).c_str());
    int minute = atoi(timeStr.substr(3, 2).c_str());
    int second = atoi(timeStr.substr(6, 2).c_str());

    // Check if the time entered makes sense
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
    {
        return false;
    }

    // Store the values in the time structure
    timeStruct.hour = hour;
    timeStruct.minute = minute;
    timeStruct.second = second;

    return true;
}

void print24Hour(Time timeStruct)
{
    cout << setfill('0') << setw(2) << timeStruct.hour << ":"
         << setfill('0') << setw(2) << timeStruct.minute << ":"
         << setfill('0') << setw(2) << timeStruct.second;
}
