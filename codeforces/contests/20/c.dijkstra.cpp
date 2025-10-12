#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &path, vector<int> &distance, vector<int> &parent, vector<bool> &visited, int source, int destination)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [currentDistance, u] = pq.top();
        pq.pop();

        if (currentDistance > distance[u])
            continue;

        visited[u] = true;

        for (auto [v, weight] : adj[u])
        {
            if (!visited[v] && distance[u] + weight < distance[v])
            {
                parent[v] = u;
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    if (distance[destination] == INT_MAX)
    {
        return;
    }

    for (int node = destination; node != -1; node = parent[node])
    {
        path.push_back(node);
    }

    reverse(path.begin(), path.end());
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> path;
    vector<int> parent(adj.size(), -1);
    vector<bool> visited(adj.size(), false);
    vector<int> distance(adj.size(), INT_MAX);

    dijkstra(adj, path, distance, parent, visited, 1, n);

    if (path.empty())
    {
        cout << -1;
        return 0;
    }

    for (auto road : path)
    {
        cout << road << " ";
    }

    cout << endl;

    return 0;
}