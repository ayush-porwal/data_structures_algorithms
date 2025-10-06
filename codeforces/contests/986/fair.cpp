// #include <bits/stdc++.h>

// using namespace std;

// this will result into N*(N+E) type of solution. Not good for given constraints.

// int bfs(vector<vector<int>> &adj, vector<int> &typeOfGoods, int currentNode, int s)
// {
//     int ans = 0;
//     queue<int> nodes;
//     vector<int> cost(adj.size());
//     vector<bool> visited(adj.size());
//     unordered_map<int, bool> hasThisTypeOfGood;

//     nodes.push(currentNode);
//     visited[currentNode] = true;
//     hasThisTypeOfGood[typeOfGoods[currentNode]] = true;
//     s--;

//     while (!nodes.empty() && s > 0)
//     {
//         auto node = nodes.front();
//         nodes.pop();
//         visited[node] = true;

//         for (auto neighbor : adj[node])
//         {
//             if (!visited[neighbor])
//             {
//                 nodes.push(neighbor);
//                 visited[neighbor] = true;
//                 cost[neighbor] = cost[node] + 1;
//                 if (!hasThisTypeOfGood[typeOfGoods[neighbor]])
//                 {
//                     ans += cost[neighbor];
//                     hasThisTypeOfGood[typeOfGoods[neighbor]] = true;
//                     if (--s == 0)
//                         break;
//                 }
//             }
//         }
//     }

//     return ans;
// }

// int multiBfs(vector<vector<int>> &adj) {}

// int main()
// {
//     int n, m, k, s;
//     cin >> n >> m >> k >> s;

//     vector<int> typeOfGoods(n + 1, -1);
//     vector<vector<int>> adj(n + 1, vector<int>());

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> typeOfGoods[i];
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

// Multi-source BFS: finds shortest distance from ANY source selling a particular good type
// Time: O(n + m) per call
vector<int> multiBFS(vector<vector<int>> &adj, vector<int> &sources, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;

    // Start BFS from ALL sources simultaneously (multi-source BFS)
    for (int src : sources)
    {
        q.push(src);
        dist[src] = 0;
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            // If not visited yet (distance is still INT_MAX)
            if (dist[neighbor] == INT_MAX)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> typeOfGoods(n + 1);
    vector<vector<int>> adj(n + 1);

    // Group cities by the type of good they sell
    // shops[goodType] = list of cities selling that good
    vector<vector<int>> shops(k + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> typeOfGoods[i];
        shops[typeOfGoods[i]].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // costMatrix[goodType][city] = distance from city to nearest shop selling goodType
    // We only store k distance arrays, not n*k
    vector<vector<int>> costMatrix(k + 1);

    // For each type of good, run ONE multi-source BFS
    // Time: O(k × (n + m))
    for (int goodType = 1; goodType <= k; goodType++)
    {
        costMatrix[goodType] = multiBFS(adj, shops[goodType], n);
    }

    // For each city, find the s cheapest goods to buy
    // Time: O(n × k log k)
    for (int city = 1; city <= n; city++)
    {
        vector<int> costs;

        // Collect distances to each type of good
        for (int goodType = 1; goodType <= k; goodType++)
        {
            costs.push_back(costMatrix[goodType][city]);
        }

        // Sort and take the s smallest distances
        sort(costs.begin(), costs.end());

        long long totalCost = 0;
        for (int i = 0; i < s; i++)
        {
            totalCost += costs[i];
        }

        cout << totalCost << " ";
    }

    return 0;
}