#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &numberOfLeafNodes, int currentNode, int parent)
{
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, numberOfLeafNodes, neighbor, currentNode);
        }
        else if (adj[currentNode].size() == 1)
        {
            numberOfLeafNodes[parent]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> numberOfLeafNodes(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 1; i <= n - 1; i++)
    {
        int parent;
        cin >> parent;

        adj[parent].push_back(i + 1);
        adj[i + 1].push_back(parent);
    }

    dfs(adj, numberOfLeafNodes, 1, -1);

    bool spruce = true;

    for (int i = 1; i <= n; i++)
    {
        if (numberOfLeafNodes[i] >= 3 || (numberOfLeafNodes[i] == 0 && adj[i].size() == 1))
        {
            continue;
        }
        else
        {
            spruce = false;
        }
    }

    cout << (spruce ? "Yes\n" : "No\n");

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int par[N], children[N], isPar[N];

int main()
{
    int n, flag = 1;
    cin >> n;

    for (int i = 2; i <= n; i++)
        cin >> par[i];

    for (int i = n; i >= 1; i--)
    {
        if (isPar[i] == 0)
            children[par[i]]++;
        else
            flag &= (children[i] >= 3);

        isPar[par[i]] = 1;
    }

    cout << (flag ? "Yes" : "No");
}