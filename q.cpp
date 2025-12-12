#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<pair<int, int>> tests(t);
    int max_m = 0;
    for (int i = 0; i < t; ++i)
    {
        cin >> tests[i].first >> tests[i].second;
        max_m = max(max_m, tests[i].second);
    }

    vector<vector<long long>> dp(10, vector<long long>(max_m + 1));

    for (int i = 0; i < 10; ++i)
    {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= max_m; ++j)
    {
        for (int i = 0; i < 9; ++i)
        {
            dp[i][j] = dp[i + 1][j - 1];
        }
        dp[9][j] = (dp[1][j - 1] + dp[0][j - 1]) % MOD;
    }

    for (const auto &test : tests)
    {
        long long n = test.first;
        int m = test.second;

        long long total_length = 0;
        string s = to_string(n);

        for (char c : s)
        {
            int digit = c - '0';
            total_length = (total_length + dp[digit][m]) % MOD;
        }

        cout << total_length << "\n";
    }

    return 0;
}