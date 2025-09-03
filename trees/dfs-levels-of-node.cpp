#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &nodeLevels, int currentNode, int parent, int level)
{
    nodeLevels[currentNode] = level;
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, nodeLevels, neighbor, currentNode, level + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nodeLevels(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj, nodeLevels, 1, -1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": Level " << nodeLevels[i] << "\n";
    }

    cout << "\n";

    return 0;
}