#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> stones(n, 0);

    for (auto &stone : stones)
    {
        cin >> stone;
    }

    int m;
    cin >> m;

    vector<long long> prefix(n, 0);
    prefix[0] = stones[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + stones[i];
    }

    sort(stones.begin(), stones.end());

    vector<long long> sortedPrefix(n, 0);
    sortedPrefix[0] = stones[0];
    for (int i = 1; i < n; i++)
    {
        sortedPrefix[i] = sortedPrefix[i - 1] + stones[i];
    }

    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        l--, r--;

        if (t == 1)
        {
            cout << prefix[r] - (l - 1 >= 0 ? prefix[l - 1] : 0) << endl;
        }
        else
        {
            cout << sortedPrefix[r] - (l - 1 >= 0 ? sortedPrefix[l - 1] : 0) << endl;
        }
    }

    return 0;
}