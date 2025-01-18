#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;

        long long sumOfArr = 0;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sumOfArr += a[i] + 0ll;
        }

        long long ans = 0;

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            int lbound = lower_bound(a.begin(), a.end(), sumOfArr - y - a[i]) - a.begin();
            int rbound = upper_bound(a.begin(), a.end(), sumOfArr - x - a[i]) - a.begin();

            ans += max(0, rbound - lbound) + 0ll;

            if (lbound <= i && i < rbound)
            {
                ans--;
            }
        }

        cout << ans / 2 << "\n";
    }

    return 0;
}