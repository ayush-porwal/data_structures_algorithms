#include <bits/stdc++.h>

using namespace std;

vector<int> getTopThreeMax(vector<int> &v)
{
    int m1 = -1, m2 = -1, m3 = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (m1 == -1 || v[m1] < v[i])
        {
            m3 = m2;
            m2 = m1;
            m1 = i;
        }
        else if (m2 == -1 || v[m2] < v[i])
        {
            m3 = m2;
            m2 = i;
        }
        else if (m3 == -1 || v[m3] < v[i])
        {
            m3 = i;
        }
    }

    return {m1, m2, m3};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        int ans = 0;

        for (auto i : getTopThreeMax(a))
        {
            for (auto j : getTopThreeMax(b))
            {
                for (auto k : getTopThreeMax(c))
                {
                    if (i != j && i != k && j != k)
                    {
                        ans = max(ans, a[i] + b[j] + c[k]);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}