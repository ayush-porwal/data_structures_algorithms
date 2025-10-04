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

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    UnionGet ug(n);

    for (int i = 1; i <= m; i++)
    {
        string query;
        int u, v;

        cin >> query >> u >> v;

        if (query == "union")
        {
            ug.UNION(--u, --v);
        }
        else
        {
            cout << (ug.FIND(--u) == ug.FIND(--v) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}