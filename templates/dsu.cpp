#include <bits/stdc++.h>

class UnionFind
{
private:
    std::vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        std::iota(parent.begin(), parent.end(), 0);
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
                std::swap(u, v);
            }

            parent[v] = u;

            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
};