#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int currentNode, int parent)
{
    visited[currentNode] = true;

    for (auto neighbor : adj[currentNode])
    {
        if (visited[neighbor])
        {
            continue;
        }

        if (parent != neighbor)
        {
            dfs(adj, visited, neighbor, currentNode);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int count = 0;
    vector<int> uniqueNodes;
    vector<bool> visited(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            uniqueNodes.push_back(i);
            dfs(adj, visited, i, -1);
        }
    }

    cout << count - 1 << "\n";

    for (int i = 1; i < uniqueNodes.size(); i++)
    {
        cout << uniqueNodes[i] << " " << uniqueNodes[i - 1] << "\n";
    }

    return 0;
}