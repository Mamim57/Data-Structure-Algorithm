#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // The element to be inserted in the sorted part
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // one position ahead to make space for the key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n; // Input the size of the array

    int arr[n]; // Declare an array of size 'n'
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n); // Call insertion sort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

