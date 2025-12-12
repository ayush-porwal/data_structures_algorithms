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
        vector<int> nums(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int odds = 0;

        for (auto item : nums)
        {
            if (item % 2 != 0)
                odds++;
        }

        if (n - odds >= 2)
            cout << 0 << "\n";
        else if (n - odds == 1)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }

    return 0;
}