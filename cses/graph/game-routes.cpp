#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

void tSort(vector<vector<int>> &adj, vector<int> &order, vector<bool> &visited, int currentNode)
{
    visited[currentNode] = true;

    for (auto neighbor : adj[currentNode])
    {
        if (!visited[neighbor])
            tSort(adj, order, visited, neighbor);
    }
    order.push_back(currentNode);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> order;
    vector<int> ways(n, 0);
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    tSort(adj, order, visited, 0);

    reverse(order.begin(), order.end());

    ways[0] = 1;

    for (auto currentNode : order)
    {
        for (auto node : adj[currentNode])
        {
            ways[node] = (ways[node] + ways[currentNode]) % MOD;
        }
    }

    cout << ways[n - 1] << endl;

    return 0;
}