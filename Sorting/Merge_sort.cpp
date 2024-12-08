#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid, int high)
{
    int i,j,k;

    int n1 = mid - low+1;
    int n2 = high - mid;

    int L[n1], M[n2];

    for(int i=0;i<n1;i++) L[i] = arr[low+i];
    for(int j=0;j<n2;j++) M[j] = arr[mid+1+j];

    i = 0;
    j= 0;
    k = low;

    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }


}

int merge_sort(int arr[],int low, int high)
{
    if(low<high)
    {
        int mid = low + (high-low)/2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}


