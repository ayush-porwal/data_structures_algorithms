#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    // dp[i][j] = minimum number of cuts required to convert the sqaure of dimensions i x j into sqaures
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int v = 1; v <= i - 1; v++)
                {
                    dp[i][j] = min(dp[i][j], dp[v][j] + dp[i - v][j] + 1);
                }

                for (int h = 1; h <= j - 1; h++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}