#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<pair<int, int>> grid;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid.push_back({x, y});
    }

    queue<pair<int, int>> q;
    map<pair<int, int>, pair<int, int>> ans;
    set<pair<int, int>> points(grid.begin(), grid.end());

    for (auto [x, y] : grid)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (points.find({nx, ny}) != points.end())
                continue;
            ans[{x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (points.find({nx, ny}) == points.end() || ans.count({nx, ny}))
                continue;
            ans[{nx, ny}] = ans[{x, y}];
            q.push({nx, ny});
        }
    }

    for (auto [x, y] : grid)
    {
        auto [a, b] = ans[{x, y}];
        cout << a << " " << b << endl;
    }

    return 0;
}