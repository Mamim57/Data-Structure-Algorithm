#include <bits/stdc++.h>
using namespace std;

// Recursive function for linear search
int linearSearch(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1; // Base case: element not found
    }
    if (arr[n - 1] == x)
    {
        return n - 1; // Element found at index n-1
    }
    return linearSearch(arr, n - 1, x); // Recursive call with smaller size
}

int main()
{
    int n, x;

    // Input array size and elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input the element to search
    cout << "Enter the element to search: ";
    cin >> x;

    // Perform linear search
    int result = linearSearch(arr, n, x);

    // Output result
    if (result == -1)
    {
        cout << x << " not found in the array." << endl;
    }
    else
    {
        cout << x << " found at index " << result << "." << endl;
    }

    return 0;
}

