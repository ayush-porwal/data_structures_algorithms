#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp[i] = number of way to get the sum i
    vector<int> dp(n + 1, 0);

    // filling dp[i=1 to 6] = 1 because we can attain these in one way
    // bigger values, we can't so we don't do anything for them
    fill(dp.begin() + 1, dp.begin() + 1 + min(6, n), 1);

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j > 0)
            {
                dp[i] = dp[i] % MOD;
                dp[i] += dp[i - j] % MOD;
            }
        }
    }

    cout << dp[n] % MOD;

    return 0;
}