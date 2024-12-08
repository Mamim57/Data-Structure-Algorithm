#include <bits/stdc++.h>
using namespace std;

// Interpolation search function
int interpolationSearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        // Calculate the position using the interpolation formula
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // If key is found
        if (arr[pos] == key)
            return pos;

        // If key is larger, move to the right
        if (arr[pos] < key)
            low = pos + 1;

        // If key is smaller, move to the left
        else
            high = pos - 1;
    }

    return -1; // Key not found
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = interpolationSearch(arr, n, key);

    if (result == -1)
        cout << "Element not found in the array." << endl;
    else
        cout << "Element found at index " << result << "." << endl;

    return 0;
}

