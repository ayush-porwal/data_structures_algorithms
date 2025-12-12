#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    vector<vector<pair<int, ll>>> adj(n + 1, vector<pair<int, ll>>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Priority queue: {distance, {node, discount_used}}
    // discount_used: 0 = not used, 1 = used
    priority_queue<pair<ll, pair<int, int>>,
                   vector<pair<ll, pair<int, int>>>,
                   greater<pair<ll, pair<int, int>>>>
        pq;

    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();

        // If we've already found a better path to this state, skip
        if (d > dist[u][used])
            continue;

        // Explore all neighbors
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            ll w = edge.second;

            // Case 1: Don't use discount on this edge
            if (dist[v][used] > dist[u][used] + w)
            {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], {v, used}});
            }

            // Case 2: Use discount on this edge (only if not used yet)
            if (used == 0)
            {
                ll new_dist = dist[u][0] + w / 2;
                if (dist[v][1] > new_dist)
                {
                    dist[v][1] = new_dist;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
    }

    // Answer is reaching node n with discount used
    cout << dist[n][1] << "\n";

    return 0;
}