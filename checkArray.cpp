#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int checkArraySort(string *A, int array_size)
{
    int ascdesc = 0;

    // Check if the array is in ascending order
    bool ascending = true;
    for (int i = 1; i < array_size; i++)
    {
        if (A[i] < A[i - 1])
        {
            ascending = false;
            break;
        }
    }

    // Check if the array is in descending order
    bool descending = true;
    for (int i = 1; i < array_size; i++)
    {
        if (A[i] > A[i - 1])
        {
            descending = false;
            break;
        }
    }

    if (ascending)
    {
        ascdesc = 1;
    }
    else if (descending)
    {
        ascdesc = -1;
    }

    return ascdesc;
}