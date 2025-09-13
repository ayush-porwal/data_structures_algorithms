#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<vector<int>>> &adj, vector<int> &result, vector<long long> &bprefix, int currentNode, int parent, long long atot, long long btot)
{
    for (auto neighbor : adj[currentNode])
    {
        if (neighbor[0] != parent)
        {

            bprefix.push_back(0LL + btot + neighbor[2]);
            result[neighbor[0]] = upper_bound(bprefix.begin(), bprefix.end(), atot + neighbor[1]) - bprefix.begin();
            dfs(adj, result, bprefix, neighbor[0], currentNode, atot + neighbor[1], btot + neighbor[2]);
            bprefix.pop_back();
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> result(n + 1);
        vector<long long> bprefix;
        vector<vector<vector<int>>> adj(n + 1);

        for (int j = 1; j <= n - 1; j++)
        {
            int p, a, b;
            cin >> p >> a >> b;

            adj[j + 1].push_back({p, a, b});
            adj[p].push_back({j + 1, a, b});
        }

        dfs(adj, result, bprefix, 1, -1, 0, 0);

        for (int i = 2; i < n + 1; i++)
        {
            cout << result[i] << " ";
        }

        cout << endl;
    }

    return 0;
}