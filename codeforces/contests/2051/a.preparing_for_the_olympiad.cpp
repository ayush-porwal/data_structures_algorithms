#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = 0;
        for (int i = 0, j = i + 1; i < n; i++)
        {
            if (a[i] > b[j] && j < n)
            {
                ans += a[i] - b[j];
            }
            j++;
        }

        cout << ans + a[n - 1] << "\n";
    }

    return 0;
}
