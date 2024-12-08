#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>&dp)
{
    if(n==0||n==1) return n;
    else if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
    return dp[n];
}
int main()
{
    int n; cin>>n;
    vector<int> dp(n+1,-1);
    int result = fibonacci(n,dp);
    cout<<result<<endl;
    return 0;
}
