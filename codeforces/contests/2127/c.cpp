#include <bits/stdc++.h>

using namespace std;

// int solve(vector<int> &a, vector<int> &b, int n)
// {
//     int ans  = 0;

//     for (int i = 0; i < n; i++)
//     {
//     ans +=
//     }
// }

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n), diff(n);

        for (auto &item : a)
        {
            cin >> item;
        }

        for (auto &item : b)
        {
            cin >> item;
        }

        int minDiff = INT_MAX, maxDiff = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            diff[i] = abs(a[i] - b[i]);

            if (minDiff > diff[i])
            {
                minDiff = i;
            }

            if (maxDiff < diff[i])
            {
                maxDiff = i;
            }
        }

        while (k--)
        {
            int initialSum = accumulate(diff.begin(), diff.end(), 0);
            // swap(a)
        }
    }
    return 0;
}