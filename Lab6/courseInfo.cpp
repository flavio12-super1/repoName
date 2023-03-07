#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for atof
#include <vector>

using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

struct Course
{
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    Time startTime;
    Time endTime;
};

Time convertToTime(string timeString)
{
    Time t;
    sscanf(timeString.c_str(), "%d:%d:%d", &t.hour, &t.minute, &t.second);
    return t;
}

void printTime(Time t)
{
    string suffix = "am";
    int hour = t.hour;
    if (hour >= 12)
    {
        suffix = "pm";
        if (hour > 12)
        {
            hour -= 12;
        }
    }
    printf("%d:%02d:%02d%s", hour, t.minute, t.second, suffix.c_str());
}

int main()
{
    ifstream infile("in.txt");
    int numCourses;
    infile >> numCourses;

    vector<Course> courses;
    for (int i = 0; i < numCourses; i++)
    {
        Course c;
        infile >> c.name;
        infile >> c.credits;
        int majorRequirementInt;
        infile >> majorRequirementInt;
        c.majorRequirement = (majorRequirementInt == 1);
        string avgGradeString;
        infile >> avgGradeString;
        c.avgGrade = atof(avgGradeString.c_str());
        string days;
        getline(infile >> ws, days); // read the entire line, including spaces
        c.days = days;
        string startTimeString, endTimeString;
        infile >> startTimeString >> endTimeString;
        c.startTime = convertToTime(startTimeString);
        c.endTime = convertToTime(endTimeString);
        courses.push_back(c);
    }

    cout << "−−−−−−−−−−−−−−−−−−−\n";
    cout << "SCHEDULE OF STUDENT\n";
    cout << "−−−−−−−−−−−−−−−−−−−\n";

    for (int i = 0; i < numCourses; i++)
    {
        cout << "COURSE " << i + 1 << ": " << courses[i].name << "\n";
        if (courses[i].majorRequirement)
        {
            cout << "Note: this course is a major requirement!\n";
        }
        else
        {
            cout << "Note: this course is not a major requirement...\n";
        }
        cout << "Number of Credits: " << courses[i].credits << "\n";
        cout << "Days of Lectures: " << courses[i].days << "\n";
        cout << "Lecture Time: ";
        printTime(courses[i].startTime);
        cout << " - ";
        printTime(courses[i].endTime);
        cout << "\n";
        printf("Stat: on average students get %.0f%% in this course.\n", courses[i].avgGrade);
        cout << "\n";
    }

    infile.close();
    return 0;
}
