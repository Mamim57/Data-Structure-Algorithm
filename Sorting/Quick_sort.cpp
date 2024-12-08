#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low, int high)
{
    int pivot = arr[low];
    int i=low+1;
    int j=high;

    while(i<=j)
    {
        while(i<=high && arr[i]<=pivot) i++;
        while(j>=low && arr[j]>pivot) j--;
        if(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

int quick_sort(int arr[],int low, int high)
{
    if(low<high)
    {
        int pivot = partition(arr,low,high);

        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

