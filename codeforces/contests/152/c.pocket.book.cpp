#include <bits/stdc++.h>

using namespace std;

#define Mod 1000000007

long long mod_mul(long long a, long long b)
{
    a %= Mod;
    b %= Mod;
    return (((a * b) % Mod) + Mod) % Mod;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> names;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        names.push_back(s);
    }

    long long ans = 1;

    for (int i = 0; i < m; i++)
    {
        set<int> unique;
        for (int j = 0; j < n; j++)
        {
            unique.insert(names[j][i]);
        }
        ans = mod_mul(ans, (long long)unique.size());
    }

    cout << ans << "\n";

    return 0;
}