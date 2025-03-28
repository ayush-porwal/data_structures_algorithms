#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    const int mod = 1000000007;

    int totalSum = 1ll * n * (n + 1) / 2;

    // when the total sum is odd, it can't be divided into sets of equal sum
    if (totalSum % 2 != 0)
    {
        cout << 0 % mod;
        return 0;
    }

    // when the sum is even
    // dp[i][j] = num of ways to form sum j using the first i numbers from 1
    vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));

    for (int i = 0; i <= totalSum; i++)
    {
        dp[0][i] = 0 % mod;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1 % mod;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= totalSum / 2; j++)
        {
            if (j >= i)
            {
                // ways where dont pick i + we pick i so we add ways to get sum j-i
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

            dp[i][j] %= mod;
        }
    }

    // we need to divide by 2, because if totalSum/2 is possible by first i elements where i<n
    // then remaining elements will also form the totalSum/2 elememts
    cout << (dp[n][totalSum / 2] * 1ll * 500000004) % mod;

    return 0;
}