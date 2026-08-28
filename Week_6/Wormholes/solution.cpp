#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {

        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);

        for (int i = 0; i < m; i++)
        {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        vector<int> dist(n, INF);

        // Start from the solar system
        dist[0] = 0;

        // Relax every edge n-1 times
        for (int i = 0; i < n - 1; i++)
        {

            for (auto edge : edges)
            {

                int u = edge.u;
                int v = edge.v;
                int w = edge.w;

                if (dist[u] != INF &&
                    dist[v] > dist[u] + w)
                {

                    dist[v] = dist[u] + w;
                }
            }
        }

        // One more pass:
        // if anything can still be relaxed,
        // there is a negative cycle.

        bool negativeCycle = false;

        for (auto edge : edges)
        {

            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INF &&
                dist[v] > dist[u] + w)
            {

                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }

    return 0;
}