#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &distance, int currentNode)
{
    queue<int> nodes;

    nodes.push(currentNode);
    distance[currentNode] = 0;
    visited[currentNode] = true;

    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();

        for (auto neighbor : adj[node])
        {
            // to handle double pushes, this if condition should avoid pushing same node twice into the queue
            if (!visited[neighbor])
            {
                nodes.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
            }

            if (neighbor == currentNode)
            {
                distance[neighbor] = distance[node] + 1;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n);
        vector<int> distance(n, -1);

        if (bfs(adj, visited, distance, i))
        {
            cout << distance[i] << endl;
        }
        else
        {
            cout << "NO WAY\n";
        }
    }

    return 0;
}