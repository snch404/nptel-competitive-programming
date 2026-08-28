#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int INF = 1e9;

int dist[N][N];

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v;
    int tc = 1;

    while (cin >> u >> v)
    {

        if (u == 0 && v == 0)
            break;

        // Initialize graph
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                dist[i][j] = INF;
            }
        }

        for (int i = 1; i < N; i++)
            dist[i][i] = 0;

        // Keep track of pages that actually exist
        set<int> pages;

        // Read first edge
        dist[u][v] = 1;
        pages.insert(u);
        pages.insert(v);

        // Read remaining edges
        while (cin >> u >> v)
        {

            if (u == 0 && v == 0)
                break;

            dist[u][v] = 1;
            pages.insert(u);
            pages.insert(v);
        }

        // Floyd-Warshall
        for (int k = 1; k < N; k++)
        {
            for (int i = 1; i < N; i++)
            {
                for (int j = 1; j < N; j++)
                {

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]);
                }
            }
        }

        // Calculate sum of shortest paths
        int sum = 0;

        for (int i : pages)
        {
            for (int j : pages)
            {

                if (i != j && dist[i][j] != INF)
                    sum += dist[i][j];
            }
        }

        int n = pages.size();

        double average = (double)sum / (n * (n - 1));

        cout << fixed << setprecision(3);
        cout << "Case " << tc++
             << ": average length between pages = "
             << average << " clicks\n";
    }

    return 0;
}