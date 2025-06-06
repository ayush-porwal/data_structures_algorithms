#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        // dp[i] = max money robber can get by stealing from first i houses
        vector<int> dp(n + 1, 0);

        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};