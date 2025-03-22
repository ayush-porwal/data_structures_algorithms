#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string setT = "";
        cin >> setT;

        long long ans = 0;
        vector<bool> removed(n + 1, false);
        vector<bool> numsT(n + 1, false);

        for (long long i = 1; i <= n; i++)
        {
            numsT[i] = setT[i - 1] == '1';
        }

        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; 1ll * i * j <= n; j++)
            {
                if (numsT[1ll * i * j])
                {
                    break;
                }
                else
                {
                    if (!removed[1ll * i * j])
                    {
                        ans += i;
                        removed[1ll * i * j] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}