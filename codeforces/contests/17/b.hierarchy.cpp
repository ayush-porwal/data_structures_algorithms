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

    int n;
    cin >> n;

    vector<bool> hasMentor(n + 1);
    vector<int> qualifications(n);
    for (auto &employeeQualfication : qualifications)
    {
        cin >> employeeQualfication;
    }

    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> applications(m);
    for (auto &edge : applications)
    {
        int u, v, w;
        cin >> u >> v >> w;
        applications.push_back({w, {u, v}});
    }
    sort(applications.begin(), applications.end());

    UnionFind uf(n + 1);

    int cost = 0;

    for (auto &[w, uv] : applications)
    {
        auto &[u, v] = uv;
        if (!hasMentor[v] && uf.FIND(u) != uf.FIND(v))
        {
            uf.UNION(u, v);
            cost += w;
            hasMentor[v] = true;
        }
    }

    int numberOfComponent = 0;

    for (int i = 1; i <= n; i++)
    {
        if (uf.FIND(i) == i)
        {
            numberOfComponent++;
        }
    }

    cout << (numberOfComponent == 1 ? cost : -1) << endl;

    return 0;
}