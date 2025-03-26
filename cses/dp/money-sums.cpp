#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int &x : coins)
        cin >> x;

    int total = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int x : coins)
    {
        for (int s = total; s >= x; s--)
        {
            if (dp[s - x])
            {
                dp[s] = true;
            }
        }
    }

    vector<int> result;
    for (int s = 1; s <= total; s++)
    {
        if (dp[s])
            result.push_back(s);
    }

    cout << result.size() << '\n';
    for (int s : result)
        cout << s << ' ';
}