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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;

        vector<int> prefix(s.size(), 0);

        prefix[0] = s[0] == '0' ? 0 : 1;

        for (int i = 1; i < s.size(); i++)
        {
            prefix[i] = (s[i] == '0' ? 0 : 1) + prefix[i - 1];
        }

        for (int i = 0; i < s.size(); i++)
        {
            int r = i - 1, l = max(0, i - k + 1);

            if (r < 0 && s[i] == '1')
            {
                ans++;
            }
            else if (s[i] == '1' && prefix[r] - (l > 0 ? prefix[l - 1] : 0) < 1)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}