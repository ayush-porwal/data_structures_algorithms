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

    int findSet(int v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);

        if (a != b)
        {
            if (rank[a] < rank[b])
            {
                std::swap(a, b);
            }

            parent[b] = a;

            if (rank[a] == rank[b])
            {
                rank[a]++;
            }
        }
    }
};