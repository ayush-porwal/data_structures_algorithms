#include <bits/stdc++.h>

using namespace std;

class MinSparseTable
{
private:
    int n, k;
    vector<vector<int>> t;

public:
    MinSparseTable(const vector<int> &arr) : n(arr.size()), k(__bit_width(n) - 1), t(k + 1, vector<int>(n, INT_MAX))
    {
        for (int j = 0; j < n; j++)
            t[0][j] = arr[j];

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j + (1 << i) - 1 <= n; j++)
            {
                t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int i = __bit_width(r - l + 1) - 1;
        return min(t[i][l], t[i][r - (1 << i) + 1]);
    }
};

class MaxSparseTable
{
private:
    int n, k;
    vector<vector<int>> t;

public:
    MaxSparseTable(const vector<int> &arr) : n(arr.size()), k(__bit_width(n) - 1), t(k + 1, vector<int>(n, INT_MAX))
    {
        for (int j = 0; j < n; j++)
            t[0][j] = arr[j];

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j + (1 << i) - 1 <= n; j++)
            {
                t[i][j] = max(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int i = __bit_width(r - l + 1) - 1;
        return max(t[i][l], t[i][r - (1 << i) + 1]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> timeToBurn(n, 0);
    for (auto &time : timeToBurn)
    {
        cin >> time;
    }

    int q;
    cin >> q;

    MinSparseTable minst(timeToBurn);
    MaxSparseTable maxst(timeToBurn);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        double ans = (double)minst.query(l, r);

        double remainder1 = (double)max((l > 0 ? maxst.query(0, l - 1) : 0), (r < n - 1 ? maxst.query(r + 1, n - 1) : 0));
        double remainder2 = (double)((maxst.query(l, r) - minst.query(l, r)) / 2.0);
        if (remainder1 > remainder2)
        {
            ans += remainder1;
        }
        else
        {
            ans += remainder2;
        }

        cout << fixed << setprecision(1) << ans << '\n';
    }
    return 0;
}