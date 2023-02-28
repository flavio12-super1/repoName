#include <iostream>
#include <fstream>
#include <string>
#include "checkArray.cpp"
using namespace std;

int main()
{
    ifstream words_in;
    ofstream words_out;
    string line;
    int size = 0;
    words_in.open("words_in.txt");
    words_out.open("words_out.txt");
    while (!words_in.eof())
    {
        getline(words_in, line);
        words_out << line << "\n";
        size++;
    }
    string *stringArray = new string[size];

    words_in.close();

    // Re-open the input file

    words_in.open("words_in.txt");
    int i = 0;
    while (!words_in.eof())
    {
        getline(words_in, line);
        stringArray[i] = line;
        i++;
    }

    // Print the words in the array
    // for (int i = 0; i < size; i++)
    // {
    //     cout << stringArray[i] << endl;
    // }

    words_in.close();
    words_out.close();

    int checker = checkArraySort(stringArray, size);
    if (checker == 1)
    {
        cout << "The array is sorted in ascending order!" << endl;
    }
    else if (checker == -1)
    {
        cout << "The array is sorted in descending order!" << endl;
    }
    else
    {
        cout << "The array is not sorted!" << endl;
    }
    return 0;
}