#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp[i][j] = number of paths from (i,j) to (n-1, n-1);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<char>> matrix(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // base case: dp[i]dp[n-1] = 1 or 0 & do[n-1][j] = 1 or 0
    // trasition state: dp[i][j] = dp[i+1][j] + dp[i][j+1]
    for (int i = n - 1; i >= 0; i--)
    {
        if (matrix[i][n - 1] == '*')
            break;
        dp[i][n - 1] = 1;
    }

    for (int j = n - 1; j >= 0; j--)
    {
        if (matrix[n - 1][j] == '*')
            break;
        dp[n - 1][j] = 1;
    }

    dp[n - 1][n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (matrix[i + 1][j] == '*' && matrix[i][j + 1] == '*')
                dp[i][j] = 0 % MOD;
            else if (matrix[i + 1][j] == '*')
                dp[i][j] = dp[i][j + 1] % MOD;
            else if (matrix[i][j + 1] == '*')
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j] % MOD + dp[i][j + 1] % MOD;
        }
    }

    cout << (matrix[0][0] == '*' ? 0 : dp[0][0] % MOD) << endl;

    return 0;
}