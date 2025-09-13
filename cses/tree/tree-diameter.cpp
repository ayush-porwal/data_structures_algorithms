#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &distX, int currentNode, int parent, int distance)
{
    distX[currentNode] = distance;
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, distX, neighbor, currentNode, distance + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> distX(n + 1);
    vector<int> distY(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj, distX, 1, -1, 0);

    int itr = max_element(distX.begin(), distX.end()) - distX.begin();

    dfs(adj, distY, itr, -1, 0);

    cout << *max_element(distY.begin(), distY.end());

    return 0;
}