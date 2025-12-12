#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        if (n <= 2)
        {
            cout << 0 << endl;
        }
        else if (n == 3)
        {
            cout << 1 << endl;
        }
        else
        {
            vector<long long int> ans(n + 1);
            ans[0] = 0;
            ans[1] = 0;
            ans[2] = 0;
            ans[3] = 1;
            for (int i = 4; i <= n; i++)
            {
                int pizzaLeft = i - (i / 3);
                ans[i] = 0LL + i / 3 + ans[pizzaLeft % 2 == 0 ? pizzaLeft / 2 : pizzaLeft / 2 + 1];
            }
            cout << ans[n] << endl;
        }
    }

    return 0;
}