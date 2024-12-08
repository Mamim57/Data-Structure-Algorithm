#include <bits/stdc++.h>
using namespace std;

// Recursive binary search function
int binary_search(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2; // Calculate the middle index

        if (arr[mid] == key) return mid;           // Key found at mid
        else if (arr[mid] > key)                  // Search in the left half
            return binary_search(arr, low, mid - 1, key);
        else                                      // Search in the right half
            return binary_search(arr, mid + 1, high, key);
    }
    return -1; // Key not found
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n; // Input the size of the array

    int arr[n];
    cout << "Enter " << n << " sorted elements (ascending order): ";
    for (int i = 0; i < n; i++) cin >> arr[i]; // Input array elements

    cout << "Enter the value you want to search for: ";
    int key;
    cin >> key; // Input the value to search

    // Perform binary search
    int position = binary_search(arr, 0, n - 1, key);

    // Output the result
    if (position == -1)
        cout << "The value " << key << " is not present in the array." << endl;
    else
        cout << "The value " << key << " is found at index " << position << endl;

    return 0;
}
