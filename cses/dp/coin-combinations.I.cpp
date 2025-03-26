#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;

    cin >> n >> x;

    vector<int> coins(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<long long int> dp(x + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (auto coin : coins)
        {
            if (i - coin >= 0)
                dp[i] += dp[i - coin];
        }
        dp[i] %= 1000000007;
    }

    cout << dp[x];

    return 0;
}
