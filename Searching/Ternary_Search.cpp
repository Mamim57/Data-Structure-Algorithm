#include <bits/stdc++.h>
using namespace std;

// Recursive ternary search function
int ternarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        // Divide the range into three parts
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        // Check if the key is at either mid1 or mid2
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        // Narrow down the search range
        if (key < arr[mid1]) // Key is in the first third
            return ternarySearch(arr, low, mid1 - 1, key);
        else if (key > arr[mid2]) // Key is in the third third
            return ternarySearch(arr, mid2 + 1, high, key);
        else // Key is in the middle third
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
    return -1; // Key not found
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements (ascending order): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the value you want to search for: ";
    int key;
    cin >> key;

    // Perform ternary search
    int position = ternarySearch(arr, 0, n - 1, key);

    // Output the result
    if (position == -1)
        cout << "The value " << key << " is not present in the array." << endl;
    else
        cout << "The value " << key << " is found at index " << position << endl;

    return 0;
}


