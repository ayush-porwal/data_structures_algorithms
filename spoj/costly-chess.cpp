#include <bits/stdc++.h>

using namespace std;

int getPoint(int a, int b)
{
    return (a * 8) + b;
}

bool isInGrid(int a, int b)
{
    return a >= 0 && a < 8 && b >= 0 && b < 8;
}

int dijkstra(int a, int b, int c, int d)
{
    vector<bool> visited(65, false);
    vector<int> distance(65, INT_MAX);
    vector<int> dx = {1, -1, 1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, 2, -2, -2, 1, -1, 1, -1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    distance[getPoint(a, b)] = 0;
    pq.push({0, {a, b}});

    while (!pq.empty())
    {
        auto [currentDistance, node] = pq.top();
        auto [currA, currB] = node;
        auto u = getPoint(currA, currB);
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int i = 0; i < 8; i++)
        {
            int newA = currA + dx[i];
            int newB = currB + dy[i];

            if (isInGrid(newA, newB))
            {
                auto v = getPoint(newA, newB);
                if (!visited[getPoint(newA, newB)] && distance[u] + (currA * newA + currB * newB) < distance[v])
                {
                    distance[v] = distance[u] + (currA * newA + currB * newB);
                    pq.push({distance[v], {newA, newB}});
                }
            }
        }
    }

    return (distance[getPoint(c, d)] == INT_MAX ? -1 : distance[getPoint(c, d)]);
}

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        cout << dijkstra(a, b, c, d) << endl;
    }
    return 0;
}