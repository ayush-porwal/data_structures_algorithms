#pragma once

#include <algorithm>
#include <utility>
#include <vector>

/**
 * Sparse table that can be instantiated with any associative merge function.
 * Complexity: build O(n log n), query O(1).
 */
template <typename T, typename Merge>
class SparseTable
{
public:
    SparseTable() = default;

    SparseTable(const std::vector<T> &data, Merge mergeFn, T identityVal = T())
    {
        build(data, std::move(mergeFn), identityVal);
    }

    void build(const std::vector<T> &data, Merge mergeFn, T identityVal = T())
    {
        merge = std::move(mergeFn);
        identity = identityVal;

        n = static_cast<int>(data.size());
        if (n == 0)
        {
            levels = 0;
            table.clear();
            log2.assign(1, 0);
            return;
        }

        levels = 32 - __builtin_clz(static_cast<unsigned int>(n));
        table.assign(levels, std::vector<T>(n));
        table[0] = data;

        log2.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            log2[i] = log2[i / 2] + 1;
        }

        for (int j = 1; j < levels; ++j)
        {
            int len = 1 << j;
            int half = len >> 1;
            for (int i = 0; i + len <= n; ++i)
            {
                table[j][i] = merge(table[j - 1][i], table[j - 1][i + half]);
            }
        }
    }

    T query(int l, int r) const
    {
        if (n == 0 || l > r)
        {
            return identity;
        }
        l = std::max(l, 0);
        r = std::min(r, n - 1);
        if (l > r)
        {
            return identity;
        }
        int len = r - l + 1;
        int j = log2[len];
        return merge(table[j][l], table[j][r - (1 << j) + 1]);
    }

    int size() const
    {
        return n;
    }

private:
    int n = 0;
    int levels = 0;
    Merge merge;
    T identity{};
    std::vector<std::vector<T>> table;
    std::vector<int> log2{0};
};

template <typename T, typename Merge>
SparseTable(const std::vector<T> &, Merge, T = T()) -> SparseTable<T, std::decay_t<Merge>>;

/**
 * Usage example:
 *
 * vector<int> a = {...};
 * auto st = SparseTable(a, [](int x, int y) { return min(x, y); }, numeric_limits<int>::max());
 * int mn = st.query(l, r);
 */
