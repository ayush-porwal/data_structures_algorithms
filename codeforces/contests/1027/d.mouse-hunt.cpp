#include <bits/stdc++.h>

using namespace std;

int findMinInCycle(vector<vector<int>> &edges, vector<int> &cost, int startNode)
{
    int minCost = INT_MAX;
    int current = startNode;

    do
    {
        minCost = min(minCost, cost[current - 1]);
        current = edges[current][0];
    } while (current != startNode);

    return minCost;
}

int dfs(vector<vector<int>> &edges, vector<int> &cost, vector<int> &state, int currentNode)
{
    if (state[currentNode] == 2)
        return INT_MAX;

    if (state[currentNode] == 1)
    {
        return findMinInCycle(edges, cost, currentNode);
    }

    state[currentNode] = 1;

    int ans = INT_MAX;
    for (auto neighbor : edges[currentNode])
    {
        int result = dfs(edges, cost, state, neighbor);
        ans = min(ans, result);
    }

    state[currentNode] = 2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cost(n);

    for (auto &trap : cost)
    {
        cin >> trap;
    }

    vector<int> moves(n);

    for (auto &move : moves)
    {
        cin >> move;
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> edges(n + 1, vector<int>());

    for (int i = 1; i <= n; i++)
    {
        edges[i].push_back(moves[i - 1]);
    }

    vector<int> state(n + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
        {
            int result = dfs(edges, cost, state, i);
            if (result != INT_MAX)
            {
                ans += result;
            }
        }
    }

    cout << ans << endl;

    return 0;
}