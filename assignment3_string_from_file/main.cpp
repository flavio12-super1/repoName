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

int binarySearchR(string *a, string key, int low, int high)
{
    if (low > high)
    {
        // Key not found
        return -1;
    }

    int mid = (low + high) / 2;

    if (a[mid] == key)
    {
        // Key found
        return mid;
    }
    else if (a[mid] < key)
    {
        // Search right half of array
        return binarySearchR(a, key, mid + 1, high);
    }
    else
    {
        // Search left half of array
        return binarySearchR(a, key, low, mid - 1);
    }
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

    int size = 0;
    string key = "bat";

    // read number of words in the file
    while (!read.eof())
    {
        read >> word;
        size++;
    }

    // close read
    read.close();

    // Open the file to read words again
    read.open(fileName);

    string *arr = new string[size];

    int i = 0;
    while (!read.eof())
    {
        read >> word;
        arr[i] = word;

        i++;
    }

    // close the ifstream and ofstream
    read.close();

    if (checkArraySort(arr, size) == 0)
    {
        cout << "Array is not in order";
        return 0;
    };

    int index = binarySearchR(arr, key, 0, size - 1);

    if (index != -1)
    {
        cout << "Found key " << key << " at index " << index << endl;
    }
    else
    {
        cout << "The key " << key << " was not found in the array!" << endl;
    }

    return 0;
}