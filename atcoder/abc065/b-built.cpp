#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
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

public:
    int costf(pair<int, int> x, pair<int, int> y)
    {
        return min(abs(x.first - y.first), abs(x.second - y.second));
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<pair<int, pair<int, int>>> edges;

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return points[i][0] < points[j][0]; });
        for (int i = 0; i < n - 1; i++)
        {
            int u = idx[i], v = idx[i + 1];
            edges.push_back({costf({points[u][0], points[u][1]},
                                   {points[v][0], points[v][1]}),
                             {u, v}});
        }

        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return points[i][1] < points[j][1]; });
        for (int i = 0; i < n - 1; i++)
        {
            int u = idx[i], v = idx[i + 1];
            edges.push_back({costf({points[u][0], points[u][1]},
                                   {points[v][0], points[v][1]}),
                             {u, v}});
        }

        sort(edges.begin(), edges.end());

        int totalCost = 0;

        UnionFind uf(n);

        for (auto &[w, uv] : edges)
        {
            auto &[u, v] = uv;

            if (uf.FIND(u) != uf.FIND(v))
            {
                uf.UNION(u, v);
                totalCost += w;
            }
        }

        return totalCost;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    Solution S;

    cout << S.minCostConnectPoints(points) << endl;

    return 0;
}