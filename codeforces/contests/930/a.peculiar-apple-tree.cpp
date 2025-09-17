#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, unordered_map<int, int> &applesAtCurrentLevel, int currentNode, int parent, int depth)
{
    if (depth >= 1)
    {
        applesAtCurrentLevel[depth]++;
    }

    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, applesAtCurrentLevel, neighbor, currentNode, depth + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> applesAtCurrentLevel;
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 2; i <= n; i++)
    {
        int node;
        cin >> node;

        adj[node].push_back(i);
        adj[i].push_back(node);
    }

    dfs(adj, applesAtCurrentLevel, 1, -1, 0);

    int ans = 1;

    for (auto &[key, value] : applesAtCurrentLevel)
    {
        ans += value % 2;
    }

    cout << ans << endl;
}