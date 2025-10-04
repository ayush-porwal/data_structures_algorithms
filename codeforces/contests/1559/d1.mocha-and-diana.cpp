#include <bits/stdc++.h>

using namespace std;

class UnionGet
{
private:
    vector<int> parent, rank;

public:
    UnionGet(int n) : parent(n), rank(n, 0)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int FIND(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = FIND(parent[v]);
    }

    void UNION(int a, int b)
    {
        a = FIND(a);
        b = FIND(b);

        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
            {
                rank[a]++;
            }
        }
    }
};

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    UnionGet ug1(n);
    UnionGet ug2(n);

    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        ug1.UNION(--u, --v);
    }

    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        ug2.UNION(--u, --v);
    }

    int ans = 0;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ug1.FIND(i) == ug1.FIND(j) || ug2.FIND(i) == ug2.FIND(j))
            {
                continue;
            }
            else
            {
                ug1.UNION(i, j);
                ug2.UNION(i, j);

                ans++;
                edges.push_back({i + 1, j + 1});
            }
        }
    }

    cout << ans << "\n";

    for (auto [u, v] : edges)
    {
        cout << u << " " << v << "\n";
    }

    return 0;
}