#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumCoins(vector<vector<int>> &coins, int k)
    {
        int n = coins.size();

        priority_queue<pair<int, pair<int, int>>> maxHeap = {};

        for (int i = 0; i < n; i++)
        {
            maxHeap.push({coins[i][2], {i, coins[i][1] - coins[i][0] + 1}});
        }

        long long ans = 0;

        while (k > 0)
        {
            cout << "current k is: " << k << endl;

            auto item = maxHeap.top();

            cout << "item is: " << item.first << " " << item.second.first << " " << item.second.second << endl;

            if (item.second.second > 0)
            {
                if (k > item.second.second)
                {
                    ans += 1ll * item.second.second * item.first;
                    k = k - item.second.second;
                    maxHeap.pop();
                }
                else
                {
                    ans += 1ll * k * item.first;
                    k = 0;
                }
            }

            cout << "current ans, k is: " << ans << " " << k << endl;
        }

        return ans;
    }
};