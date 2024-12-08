#include<bits/stdc++.h>
using namespace std;

const int numOfCoin = 5, i = 0;
int greedyCoinChange(int c[],int n, int i)
{
    if(n==0) return 0;
    if(c[i]<=n) return 1 + greedyCoinChange(c,n-c[i],i);
    else return greedyCoinChange(c,n,i+1);
}
int main()
{
    int c[numOfCoin] = {50, 25, 20, 10, 5};
    int n = 140;
    cout<<greedyCoinChange(c,n,i);
}
