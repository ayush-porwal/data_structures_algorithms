#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m);

        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        vector<int> q(k);
        for (int i = 0; i < k; i++)
        {
            cin >> q[i];
        }

        string ans = "";

        if (k == n)
        {
            for (int i = 0; i < m; i++)
            {
                ans += "1";
            }
        }
        else if (k < n - 1)
        {
            for (int i = 0; i < m; i++)
            {
                ans += "0";
            }
        }
        else
        {
            int x = 0;
            for (int i = 1; i <= n; i++)
            {
                if (!binary_search(q.begin(), q.end(), i))
                {
                    x = i;
                }
            }

            for (int i = 0; i < m; i++)
            {
                if (a[i] == x)
                {
                    ans += '1';
                }
                else
                {
                    ans += '0';
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}