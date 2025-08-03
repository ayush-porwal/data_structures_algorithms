#include <bits/stdc++.h>

using namespace std;

long long bin_pow(long long a, long long b)
{
    long long result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result *= a;
        }
        a *= a;
        b >>= 1;
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int rw = 0, rb = 0;
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == 0)
                rw++;
            else
                rb++;
        }
        ans += bin_pow(2, rw) + bin_pow(2, rb) - 2;
    }

    for (int i = 0; i < m; i++)
    {
        int cw = 0, cb = 0;
        for (int j = 0; j < n; j++)
        {
            if (table[j][i] == 0)
                cw++;
            else
                cb++;
        }
        ans += bin_pow(2, cw) + bin_pow(2, cb) - 2;
    }

    ans -= n * m;

    cout << ans << "\n";
}