#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int checkArraySort(string *a, int array_size)
{
    int num = 0;

    // Check if the array is in ascending order
    bool ascending = true;
    for (int i = 1; i < array_size; i++)
    {
        if (a[i] < a[i - 1])
        {
            ascending = false;
            break;
        }
    }

    // Cehck if the array is in descending order
    bool descending = true;
    for (int i = 1; i < array_size; i++)
    {
        if (a[i] > a[i - 1])
        {
            descending = false;
            break;
        }
    }

    if (ascending)
    {
        num = 1;
    }
    else if (descending)
    {
        num = -1;
    }

    return num;
}
int main()
{

    char fileName[] = "words_in.txt";

    // Create an ifstream object
    ifstream read;
    read.open(fileName);

    // Check if file exist
    //  ! returns the opposite boolean value
    if (!read)
    {
        cout << "File does not exist. Terminate the program." << endl;
        return 0;
    }
    string word;

    int counter = 0;

    // read number of words in the file
    while (!read.eof())
    {
        read >> word;
        counter++;
    }

    // close read
    read.close();

    // Open the file to read words again
    read.open(fileName);

    // Create an ofstream object fout to write words to file "words_out.txt"
    ofstream fout;

    fout.open("words_out.txt");

    string *stringwords = new string[counter];

    int i = 0;
    while (!read.eof())
    {
        read >> word;
        stringwords[i] = word;

        fout << word << endl;
        i++;
    }

    // close the ifstream and ofstream
    read.close();
    fout.close();

    // Pause the program output on console

    int checker = checkArraySort(stringwords, counter);
    if (checker == 1)
    {
        cout << "The array is sorted in ascending order!" << endl;
    }
    else if (checker == -1)
    {
        cout << "This array is sorted in descending order!" << endl;
    }
    else
    {
        cout << "The array is not sorted!" << endl;
    }

    return 0;
}