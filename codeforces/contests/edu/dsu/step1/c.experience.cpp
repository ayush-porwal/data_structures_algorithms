#include <bits/stdc++.h>

class UnionFind
{
private:
    std::vector<int> parent, rank, exp;

public:
    UnionFind(int n) : parent(n), rank(n, 0), exp(n, 0)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int FIND(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return FIND(parent[u]);
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
            exp[v] -= exp[u];

            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }

    void ADD(int x, int v)
    {
        exp[FIND(v)] += x;
    }

    int GET_EXP(int v)
    {
        int ans = 0;
        while (v != parent[v])
        {
            ans += exp[v];
            v = parent[v];
        }
        ans += exp[v];
        return ans;
    }
};

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFind uf(n + 1);

    for (int i = 0; i < m; i++)
    {
        string type;
        cin >> type;
        int a, b;

        if (type == "join")
        {
            cin >> a >> b;
            uf.UNION(a, b);
        }
        else if (type == "add")
        {
            cin >> a >> b;
            uf.ADD(b, a);
        }
        else
        {
            cin >> a;
            cout << uf.GET_EXP(a) << "\n";
        }
    }

    return 0;
}