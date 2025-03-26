#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> price(n + 1, 0);
    vector<int> pages(n + 1, 0);

    // dp[i] = max number of pages user can buy when he has i money left
    vector<int> dp(x + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x];

    return 0;
}
