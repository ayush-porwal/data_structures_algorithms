#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

void dfs(vector<vector<int>> &adj, stack<int> &order, vector<bool> &visited, int currentNode)
{
    visited[currentNode] = true;

    for (auto neighbor : adj[currentNode])
    {
        if (!visited[neighbor])
            dfs(adj, order, visited, neighbor);
    }
    order.push(currentNode);
}

void dfsr(vector<vector<int>> &adjr, vector<bool> &visited, vector<int> &components, int currentNode)
{
    visited[currentNode] = true;
    components.push_back(currentNode);
    for (auto neighbor : adjr[currentNode])
    {
        if (!visited[neighbor])
            dfsr(adjr, visited, components, neighbor);
    }
}

vector<vector<int>> scc(vector<vector<int>> &adj)
{
    int n = adj.size();
    stack<int> order;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(adj, order, visited, i);
    }

    vector<vector<int>> adjr(n, vector<int>());
    for (int u = 0; u < n; u++)
    {
        for (auto v : adj[u])
        {
            adjr[v].push_back(u);
        }
    }

    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> components;

    while (!order.empty())
    {
        auto checkpost = order.top();

        if (!visited[checkpost])
        {
            vector<int> currentComponent;
            dfsr(adjr, visited, currentComponent, checkpost);
            components.push_back(currentComponent);
        }

        order.pop();
    }

    return components;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cost(n);
    for (auto &price : cost)
    {
        cin >> price;
    }

    int m;
    cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vector<vector<int>> components = scc(adj);

    long long totalCount = 1;
    long long totalMinimumCost = 0;

    for (auto component : components)
    {
        long long count = 0, minimumCost = LLONG_MAX;
        for (auto checkpost : component)
        {
            minimumCost = min(minimumCost, (long long)cost[checkpost]);
        }
        for (auto checkpost : component)
        {
            if (minimumCost == cost[checkpost])
                count++;
        }
        totalCount = (totalCount * count) % MOD;
        totalMinimumCost += minimumCost;
    }

    cout << totalMinimumCost << " " << totalCount << endl;

    return 0;
}