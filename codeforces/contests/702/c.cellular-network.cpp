#include <bits/stdc++.h>

using namespace std;

bool areCitiesCovered(vector<int> &cities, vector<int> &towers, long long mid)
{
    int j = 0;
    for (auto city : cities)
    {
        while (j < towers.size() && city > towers[j] + mid)
        {
            j++;
        }

        if (j < towers.size() && city >= towers[j] - mid && city <= towers[j] + mid)
        {
            continue;
        }

        return false;
    }
    return true;
}

int main()
{
    int m, n;

    cin >> n >> m;

    vector<int> cities(n, 0);
    vector<int> towers(m, 0);

    for (auto &city : cities)
    {
        cin >> city;
    }

    for (auto &tower : towers)
    {
        cin >> tower;
    }

    int ans = 0;
    long long l = 0, h = 1e18;

    while (l <= h)
    {
        long long m = (h - l) / 2 + l;

        if (areCitiesCovered(cities, towers, m))
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}