#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &cats, int currentNode, int parent, int catTolerance, int catsEncountered, int &ans)
{
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            if (cats[neighbor - 1] == 1)
            {
                if (catsEncountered + 1 > catTolerance)
                {
                    continue;
                }
                else
                {
                    dfs(adj, cats, neighbor, currentNode, catTolerance, catsEncountered + 1, ans);
                }
            }
            else
            {
                dfs(adj, cats, neighbor, currentNode, catTolerance, 0, ans);
            }
        }
        else
        {
            // this is leaf node i guess?
            if (adj[currentNode].size() == 1)
                ans++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;

    vector<int> cats(n);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (auto &cat : cats)
    {
        cin >> cat;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj, cats, 1, -1, m, cats[0], ans);

    cout << ans << endl;

    return 0;
}