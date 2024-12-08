#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int profit;
    int deadline;
};

bool comparison(Job a, Job b)
{
    return a.profit > b.profit;  // Sort by profit in descending order
}

void jobSequence(Job arr[], int n)
{
    sort(arr, arr + n, comparison);  // Sort jobs by profit

    bool slot[n];  // To track free time slots
    for (int i = 0; i < n; i++)
    {
        slot[i] = false;  // Initially, all slots are free
    }

    int totalProfit = 0;
    cout << "Jobs selected: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])    // If the slot is free
            {
                slot[j] = true;  // Mark it as occupied
                cout << arr[i].id << " ";  // Select the job
                totalProfit += arr[i].profit;  // Add profit
                break;
            }
        }
    }

    cout << endl;
    cout << "Total profit: " << totalProfit << endl;
}

int main()
{
    Job arr[] = {{'A', 100, 2}, {'B', 19, 1}, {'C', 27, 2}, {'D', 25, 1}, {'E', 15, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);
    jobSequence(arr, n);  // Call job scheduling function
    return 0;
}

