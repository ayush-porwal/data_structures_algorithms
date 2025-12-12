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
        int n, q;
        cin >> n >> q;

        int hasB = false;
        vector<char> typeOfMachine(n);
        for (auto &type : typeOfMachine)
        {
            cin >> type;
            if (type == 'B')
                hasB = true;
        }

        vector<int> queries(q);
        for (auto &query : queries)
        {
            cin >> query;
        }

        for (int i = 0; i < q; i++)
        {
            int ans = 0;
            if (!hasB)
            {
                cout << queries[i] << endl;
                continue;
            }

            while (queries[i] > 0)
            {
                for (int j = 0; j < n && queries[i] > 0; j++)
                {
                    if (typeOfMachine[j] == 'A')
                        queries[i]--;
                    else
                        queries[i] = queries[i] / 2;
                    ans++;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}