#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Adjacency list: AL[u] contains {v, weight}
    vector<vector<pair<int, ll>>> AL(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        // Undirected graph
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }

    // dist[i] = shortest distance from 1 to i
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    // parent[i] = previous vertex in shortest path
    vector<int> parent(n + 1, -1);
    parent[1] = 1;

    // {distance, vertex}
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>>
        pq;

    pq.push({0, 1});

    while (!pq.empty())
    {

        auto [d, u] = pq.top();
        pq.pop();

        // Ignore outdated entry
        if (d != dist[u])
            continue;

        // Try all neighbours of u
        for (auto [v, w] : AL[u])
        {

            if (dist[u] + w < dist[v])
            {

                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    // No path from 1 to n
    if (dist[n] == INF)
    {
        cout << -1 << '\n';
        return 0;
    }

    // Reconstruct path
    vector<int> path;

    int current = n;

    while (current != 1)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    // Print path
    for (int vertex : path)
    {
        cout << vertex << ' ';
    }

    cout << '\n';

    return 0;
}