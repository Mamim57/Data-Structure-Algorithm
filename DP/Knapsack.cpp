#include<bits/stdc++.h>
using namespace std;

// Prepared by Jisan
int knapSack(int C, int n, vector<int>& weight, vector<int>& value)
{
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int k = 0; k <= C; k++)
        {
            if (i == 0 || k == 0)
            {
                dp[i][k] = 0;
            }
            else if (weight[i - 1] <= k)
            {
                dp[i][k] = max(value[i - 1] + dp[i - 1][k - weight[i - 1]], dp[i - 1][k]);
            }
            else
            {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
    return dp[n][C];
}

int main()
{
    vector<int> value = { 60, 100, 120 };
    vector<int> weight = { 10, 20, 30 };
    int C = 50;
    int n = value.size();
    cout << "Maximum value in Knapsack = " << knapSack(C, n, weight, value) << endl;
    return 0;
}

