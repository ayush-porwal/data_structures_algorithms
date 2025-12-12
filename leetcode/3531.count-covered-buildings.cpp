#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        unordered_map<int, set<int>> sameXCoordinate, sameYCoordinate;

        for (const auto &building : buildings)
        {
            const auto x = building[0];
            const auto y = building[1];

            sameXCoordinate[x].insert(y);
            sameYCoordinate[y].insert(x);
        }

        int ans = 0;

        for (const auto &building : buildings)
        {
            const auto x = building[0];
            const auto y = building[1];

            auto isXYInBetween = sameXCoordinate[x].find(y) != sameXCoordinate[x].begin() && next(sameXCoordinate[x].find(y)) != sameXCoordinate[x].end();
            auto isYXInBetween = sameYCoordinate[y].find(x) != sameYCoordinate[y].begin() && next(sameYCoordinate[y].find(x)) != sameYCoordinate[y].end();

            if (isXYInBetween && isYXInBetween)
                ans++;
        }

        return ans;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> buildings = {{1, 2},
                                     {1, 1},
                                     {2, 3},
                                     {2, 2},
                                     {1, 3}};

    Solution S;
    cout << S.countCoveredBuildings(n, buildings);

    return 0;
}