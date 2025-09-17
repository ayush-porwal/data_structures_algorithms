#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<pair<int, int>>> &adj, set<int> &nodesOnPath, int lastNodeWithBadPath, int currentNode, int parent)
{
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor.first != parent)
        {
            if (neighbor.second == 2)
            {
                nodesOnPath.insert(neighbor.first);
                if (lastNodeWithBadPath != -1)
                    nodesOnPath.erase(lastNodeWithBadPath);
                dfs(adj, nodesOnPath, neighbor.first, neighbor.first, currentNode);
            }
            else
            {
                dfs(adj, nodesOnPath, lastNodeWithBadPath, neighbor.first, currentNode);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> nodesOnPath;
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;

        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
    }

    dfs(adj, nodesOnPath, -1, 1, -1);

    cout << nodesOnPath.size() << "\n";

    for (auto node : nodesOnPath)
    {
        cout << node << " ";
    }

    return 0;
}