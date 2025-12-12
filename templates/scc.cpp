#include <bits/stdc++.h>

using namespace std;

class SCC
{
private:
    int n;
    vector<int> order;
    vector<int> visited;

public:
    SCC(vector<vector<int>> adj)
    {
        n = adj.size();
        visited.assign(n, 0);
    }

    void dfs(vector<vector<int>> &adj, vector<int> &order, int currentNode)
    {
        visited[currentNode] = 1;

        for (auto neighbor : adj[currentNode])
        {
            dfs(adj, order, neighbor);
        }

        order.push_back(currentNode);
    }

    void kosaraju(vector<vector<int>> &adj)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(adj, order, i);
        }

        reverse(order.begin(), order.end());
        fill(visited.begin(), visited.end(), 0);

        vector<vector<int>> adjr(n);
        for (int u = 0; u < n; u++)
        {
            for (auto v : adj[u])
            {
                adjr[v].push_back(u);
            }
        }
    }
};