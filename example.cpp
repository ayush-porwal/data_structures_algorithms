#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<set<int>> &paths, int currentNode, int parent, int depth, bool &flag)
{

    if (flag || (depth >= 1 && adj[currentNode].size() > 2))
    {
        flag = true;
        return;
    }

    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            paths[currentNode].insert(neighbor);
            dfs(adj, paths, neighbor, currentNode, depth + 1, flag);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<set<int>> paths(n + 1, set<int>());
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool flag = false;

    dfs(adj, paths, 1, -1, 0, flag);

    cout << (flag ? "No" : "Yes");

    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!paths[i].empty())
            {
                cout << i << *paths[i].rbegin() << "\n";
            }
        }
    }

    return 0;
}