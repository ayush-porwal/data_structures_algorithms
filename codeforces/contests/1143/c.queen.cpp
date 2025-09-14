#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &hatesAncestors, vector<bool> &hatedByAllChildren, int currentNode, int parent)
{

    if (adj[currentNode].size() == 1 && parent != -1)
    {
        hatedByAllChildren[currentNode] = (hatesAncestors[currentNode] == 1);
        return;
    }

    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            hatedByAllChildren[currentNode] = hatedByAllChildren[currentNode] && hatesAncestors[neighbor];
        }
    }

    for (auto neighbor : adj[currentNode])
    {
        if (neighbor != parent)
        {
            dfs(adj, hatesAncestors, hatedByAllChildren, neighbor, currentNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int rootNode = -1;
    vector<int> hatesAncestors(n + 1);
    vector<bool> hatedByAllChildren(n + 1, true);
    vector<vector<int>> adj(n + 1, vector<int>());
    priority_queue<int, vector<int>, greater<int>> nodes;

    for (int i = 1; i < n + 1; i++)
    {
        int p, c;
        cin >> p >> c;

        hatesAncestors[i] = c;

        if (p == -1)
        {
            rootNode = i;
        }
        else
        {
            adj[p].push_back(i);
            adj[i].push_back(p);
        }

        if (c == 1 && p != -1)
        {
            nodes.push(i);
        }
    }

    bool flag = false;
    dfs(adj, hatesAncestors, hatedByAllChildren, rootNode, -1);

    while (!nodes.empty())
    {
        auto node = nodes.top();
        nodes.pop();

        if (hatedByAllChildren[node] && hatesAncestors[node])
        {
            flag = true;
            cout << node << " ";
        }
    }

    if (!flag)
        cout << -1;

    return 0;
}