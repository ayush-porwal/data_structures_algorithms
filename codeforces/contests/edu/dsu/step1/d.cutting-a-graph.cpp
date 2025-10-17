#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int FIND(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = FIND(parent[u]);
    }

    void UNION(int u, int v)
    {
        u = FIND(u);
        v = FIND(v);

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }

            parent[v] = u;

            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string edge;
    for (int i = 0; i < m; i++)
    {
        getline(cin, edge);
    }

    vector<pair<string, pair<int, int>>> operations;

    for (int i = 0; i < k; i++)
    {
        string type;
        int u, v;

        cin >> type >> u >> v;

        operations.push_back({type, {u, v}});
    }

    UnionFind uf(n + 1);
    vector<string> ans;

    for (int i = k - 1; i >= 0; i--)
    {
        auto &[type, uv] = operations[i];
        auto &[u, v] = uv;

        if (type == "ask")
        {
            if (uf.FIND(u) == uf.FIND(v))
            {
                ans.push_back("YES");
            }
            else
            {
                ans.push_back("NO");
            }
        }
        else
        {
            uf.UNION(u, v);
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}