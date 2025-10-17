#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
    vector<int> parent, size;
    int largestSize = INT_MIN, numberOfConnectedComponents;

public:
    UnionFind(int n) : parent(n), size(n, 1)
    {
        numberOfConnectedComponents = n - 1;
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
            if (size[u] < size[v])
            {
                swap(u, v);
            }

            parent[v] = u;
            size[u] += size[v];
            numberOfConnectedComponents--;
            largestSize = max(largestSize, size[u]);
        }
    }

    int getLargestSize()
    {
        return largestSize;
    }

    int getNumberOfConnectedComponents()
    {
        return numberOfConnectedComponents;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFind uf(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        uf.UNION(u, v);

        cout << uf.getNumberOfConnectedComponents() << " " << uf.getLargestSize() << endl;
    }

    return 0;
}