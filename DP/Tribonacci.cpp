#include<bits/stdc++.h>
using namespace std;

int Tribonacci(int n, vector<int>&dp)
{
    if(n==0||n==1 || n==2 ) return 0;
    if(n==3) return 1;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = Tribonacci(n-1,dp) + Tribonacci(n-2,dp) + Tribonacci(n-3,dp);
    return dp[n];
}
int main()
{
    int n; cin>>n;
    vector<int> dp(n+1,-1);
    int result = Tribonacci(n,dp);
    cout<<result<<endl;
    return 0;
}
