#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &subordinates, int currentNode, int parent)
{
    if (adj[currentNode].size() == 1 && parent != -1)
    {
        subordinates[currentNode] = 0;
        return;
    }

    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, subordinates, neighbor, currentNode);
            subordinates[currentNode] += 1 + subordinates[neighbor];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> subordinates(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 2; i <= n; i++)
    {
        int node;
        cin >> node;
        adj[node].push_back(i);
        adj[i].push_back(node);
    }

    dfs(adj, subordinates, 1, -1);

    for (int i = 1; i <= n; i++)
    {
        cout << subordinates[i] << " ";
    }

    return 0;
}