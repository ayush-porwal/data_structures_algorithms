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
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        unordered_map<char, int> sm, tm;

        for (int i = 0; i < n; i++)
        {
            sm[s[i]]++;
            tm[t[i]]++;
        }

        bool flag = true;

        for (auto key : sm)
        {
            if (sm[key.first] != tm[key.first])
            {
                flag = false;
                cout << "NO\n";
                break;
            }
        }
        if (flag)
            cout << "YES\n";
    }

    return 0;
}