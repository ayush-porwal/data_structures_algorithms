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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> m >> n && (m != 0 && n != 0))
    {

        int mstLength = 0;
        int totalLength = 0;
        vector<pair<int, pair<int, int>>> edges(n);

        for (int i = 0; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            totalLength += w;
            edges.push_back({w, {u, v}});
        }

        sort(edges.begin(), edges.end());

        UnionFind uf(n + 1);

        for (auto &[w, uv] : edges)
        {
            auto &[u, v] = uv;
            if (uf.FIND(u) != uf.FIND(v))
            {
                mstLength += w;
                uf.UNION(u, v);
            }
        }

        cout << totalLength - mstLength << endl;
    }

    return 0;
}