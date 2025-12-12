#include <bits/stdc++.h>

using namespace std;

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

    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n, vector<int>());
    vector<int> order, numberOfPredecessors(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    tSort(adj, order, visited, 0);

    numberOfPredecessors[0] = 0;
    reverse(order.begin(), order.end());

    for (auto currentNode : order)
    {
        for (auto node : adj[currentNode])
        {
            if (numberOfPredecessors[node] < numberOfPredecessors[currentNode] + 1)
            {
                parent[node] = currentNode;
            }
            numberOfPredecessors[node] = max(numberOfPredecessors[node], numberOfPredecessors[currentNode] + 1);
        }
    }

    if (numberOfPredecessors[n - 1] == 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << numberOfPredecessors[n - 1] + 1 << endl;
        int node = n - 1;
        vector<int> path;
        while (parent[node] != -1)
        {
            path.push_back(parent[node]);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        for (auto item : path)
        {
            cout << ++item << " ";
        }
        cout << n << endl;
    }

    return 0;
}