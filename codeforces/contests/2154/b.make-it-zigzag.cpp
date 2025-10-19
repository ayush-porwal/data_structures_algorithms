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
        vector<int> preMax(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        for (int i = 0; i < n; i++)

            preMax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (i - 1 >= 0)
                ans += max(0, nums[i] - preMax[i - 1] + 1);
            else if (i + 1 < n)
                ans += max(0, nums[i] - preMax[i + 1] + 1);
        }

        cout << ans << endl;
    }

    return 0;
}