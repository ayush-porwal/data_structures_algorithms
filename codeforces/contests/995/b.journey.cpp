#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        int sum = a + b + c;
        int ans = n / sum;

        if (ans * sum == n)
        {
            cout << 3 * ans << "\n";
            continue;
        }

        int arr_sum = 0;

        vector<int> v = {a, b, c};

        int j = 0;

        for (int i = 0; i < 3; i++)
        {
            if (ans * sum + v[i] + arr_sum < n)
            {
                arr_sum += v[i];
                j++;
            }
            else
            {
                j++;
                break;
            }
        }

        cout << 3 * ans + j << "\n";
    }

    return 0;
}