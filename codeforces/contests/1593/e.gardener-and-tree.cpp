#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> degrees(n + 1);
        vector<vector<int>> adj(n + 1, vector<int>());

        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);

            degrees[u]++;
            degrees[v]++;
        }

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else if (n == 1 || n == 2)
        {
            cout << 0 << endl;
            continue;
        }

        queue<int> leafs;

        for (int i = 1; i < n + 1; i++)
        {
            if (degrees[i] == 1)
                leafs.push(i);
        }

        auto initialLeafNodes = leafs.size();
        int ans = initialLeafNodes;

        while (!leafs.empty())
        {
            auto node = leafs.front();

            leafs.pop();

            for (int nei : adj[node])
            {
                if (--degrees[nei] == 1)
                {
                    leafs.push(nei);
                }
            }

            if (--initialLeafNodes == 0)
            {
                initialLeafNodes = leafs.size();
                if (--k > 0)
                {
                    ans += initialLeafNodes;
                }
                else
                {
                    break;
                }
            }
        }
        cout << n - ans << endl;
    }

    return 0;
}