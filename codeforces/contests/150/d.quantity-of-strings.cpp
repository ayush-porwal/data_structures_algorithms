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

using namespace std;

const int MOD = 1000000007;

long long mod_mul(long long a, long long b, int m)
{
    a %= m;
    b %= m;
    return (((a * b) % m) + m) % m;
}

int bin_pow(long long a, long long b, int m)
{
    long long result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result = mod_mul(result, a, m);
        }
        a = mod_mul(a, a, m);
        b >>= 1;
    }

    return result;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    UnionFind uf(n);

    for (int i = 0; i <= n - k; i++)
    {
        int left = i, right = i + k - 1;

        while (left < right)
        {
            uf.unionSets(left, right);
            left++, right--;
        }
    }

    int numberOfComponents = 0;

    for (int i = 0; i < n; i++)
    {
        if (uf.findSet(i) == i)
            numberOfComponents++;
    }

    cout << bin_pow(m, numberOfComponents, MOD);

    return 0;
}