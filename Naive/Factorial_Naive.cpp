#include<bits/stdc++.h>
using namespace std;

// Prepared by Jisan
int factorial(int n)
{
    if(n==0 || n==1) return 1;
    else return n*factorial(n-1);
}
int main()
{
    int n; cin>>n;
    int result = factorial(n);
    cout<<result<<endl;

    return 0;
}

