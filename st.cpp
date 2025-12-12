#include <bits/stdc++.h>

using namespace std;

class SparseTable
{
private:
    int k;
    vector<vector<int>> t;

public:
    SparseTable(const vector<int> &nums)
    {
        int n = (int)nums.size();
        k = (int)floor(log2(n));
        t.assign(k + 1, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; ++j)
            t[0][j] = nums[j];

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int ans = INT_MAX;

        for (int i = k; i >= 0; i--)
        {
            if ((1 << i) <= r - l + 1)
            {
                ans = min(ans, t[i][l]);
                l += 1 << i;
            }
        }

        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> nums(n, 0);
    for (auto &num : nums)
    {
        cin >> num;
    }

    SparseTable st(nums);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(l, r) << endl;
    }

    return 0;
}