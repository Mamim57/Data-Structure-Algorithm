#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;  // Input the size of the array
    int arr[n];

    // Input the array elements
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sort Algorithm
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);  // Swap if the current element is greater than the next
            }
        }
    }

    // Output the sorted array
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

