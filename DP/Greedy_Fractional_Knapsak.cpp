#include<bits/stdc++.h>
using namespace std;
struct Item {
    int profit;
    int weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};
static bool cmp(struct Item a,struct Item b)
{
    double r1 = (double)a.profit/(double)a.weight;
    double r2 = (double)b.profit/(double)b.weight;

    return r1>r2;
}
double fractional_knapsack(int c, struct Item arr[], int n)
{
    double final_profit = 0.0;
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight <= c)
        {
            c -= arr[i].weight;
            final_profit += arr[i].profit;
        }
        else
        {
            double fraction = (double)c/(double)arr[i].weight;
            final_profit += (arr[i].profit)*fraction;
            break;
        }
    }
    return final_profit;
}
int main()
{
    int c = 50;
    Item arr[] = {{60,10},{100,20},{120,30}};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout<<fractional_knapsack(c,arr,N);
    return 0;
}
