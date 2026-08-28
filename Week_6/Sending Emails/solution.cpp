#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {

        int n, m, s, t;
        cin >> n >> m >> s >> t;

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> dist(n, INF);
        dist[s] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        pq.push({0, s});

        while (!pq.empty())
        {

            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Ignore outdated entry
            if (d != dist[u])
                continue;

            for (auto edge : graph[u])
            {

                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[t] == INF)
            cout << "Case #" << tc << ": unreachable\n";
        else
            cout << "Case #" << tc << ": " << dist[t] << "\n";
    }

    return 0;
}