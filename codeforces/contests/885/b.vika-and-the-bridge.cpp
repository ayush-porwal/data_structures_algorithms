#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> colors(n);

        unordered_map<int, vector<int>> color_indexes;

        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }

        for (int i = 0; i < n; i++)
        {
            color_indexes[colors[i]].push_back(i);
        }

        int ans = INT_MAX;
        vector<int> min_max_steps(k + 1, INT_MAX);

        for (int i = 1; i <= k; i++)
        {
            int m = color_indexes[i].size();
            int max_gap = 0, sec_max_gap = 0;

            if (m == 0)
            {
                min_max_steps[i] = n / 2;
                continue;
            }

            for (int j = 1; j < m; j++)
            {
                if (color_indexes[i][j] - color_indexes[i][j - 1] - 1 >= max_gap)
                {
                    sec_max_gap = max_gap;
                    max_gap = color_indexes[i][j] - color_indexes[i][j - 1] - 1;
                }
                else if (color_indexes[i][j] - color_indexes[i][j - 1] - 1 > sec_max_gap)
                {
                    sec_max_gap = color_indexes[i][j] - color_indexes[i][j - 1] - 1;
                }
            }

            if (color_indexes[i][0] > max_gap)
            {
                sec_max_gap = max_gap;
                max_gap = color_indexes[i][0];
            }
            else if (color_indexes[i][0] > sec_max_gap)
            {
                sec_max_gap = color_indexes[i][0];
            }

            if (n - 1 - color_indexes[i][m - 1] > max_gap)
            {
                sec_max_gap = max_gap;
                max_gap = n - 1 - color_indexes[i][m - 1];
            }
            else if (n - 1 - color_indexes[i][m - 1] > sec_max_gap)
            {
                sec_max_gap = n - 1 - color_indexes[i][m - 1];
            }

            min_max_steps[i] = max(max_gap / 2, sec_max_gap);
        }

        cout << *min_element(min_max_steps.begin() + 1, min_max_steps.end()) << endl;
    }
    return 0;
}