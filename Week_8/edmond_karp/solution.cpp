#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    int tc = 1;

    while (cin >> n && n != 0)
    {
        int source, sink, m;
        cin >> source >> sink >> m;

        // capacity[u][v] = capacity of edge u -> v
        vector<vector<int>> capacity(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;

            // The connections are bidirectional
            capacity[u][v] += c;
            capacity[v][u] += c;
        }

        int maxFlow = 0;

        while (true)
        {
            // BFS to find an augmenting path
            vector<int> parent(n + 1, -1);
            queue<int> q;

            q.push(source);
            parent[source] = source;

            while (!q.empty() && parent[sink] == -1)
            {
                int u = q.front();
                q.pop();

                for (int v = 1; v <= n; v++)
                {
                    if (parent[v] == -1 && capacity[u][v] > 0)
                    {
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }

            // No augmenting path exists
            if (parent[sink] == -1)
                break;

            // Find the bottleneck capacity
            int flow = INT_MAX;

            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];
                flow = min(flow, capacity[u][v]);
            }

            // Update residual capacities
            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];

                capacity[u][v] -= flow;
                capacity[v][u] += flow;
            }

            maxFlow += flow;
        }

        cout << "Network " << tc++ << '\n';
        cout << "The bandwidth is " << maxFlow << ".\n";
    }

    return 0;
}