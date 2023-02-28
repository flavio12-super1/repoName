#include <iostream>
using namespace std;
int checkArraySort(int *a, int array_size)
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

int binarySearchR(int arr[], int key, int low, int high)
{
    if (low > high)
    {
        // Key not found
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
        // Key found
        return mid;
    }
    else if (arr[mid] < key)
    {
        // Search right half of array
        return binarySearchR(arr, key, mid + 1, high);
    }
    else
    {
        // Search left half of array
        return binarySearchR(arr, key, low, mid - 1);
    }
}

int main()
{

    int size = 9;
    int key = 2;

    int testArr[] = {1, 2, 4, 5, 6, 7, 9, 10, 11};

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = testArr[i];
    }

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