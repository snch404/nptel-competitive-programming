#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, a;
        long long x;

        cin >> n >> a >> x;

        vector<vector<long long>> adj(n, vector<long long>(n, LLONG_MAX));

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;

        int u, v;
        long long w;
        for (int i = 0; i < a; i++)
        {
            cin >> u >> v >> w;
            adj[u][v] = w;
            adj[v][u] = w;
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][via] != LLONG_MAX && adj[via][j] != LLONG_MAX)
                    {
                        adj[i][j] = min(adj[i][j],
                                        adj[i][via] + adj[via][j]);
                    }
                }
            }
        }

        int ans = 0;
        int minimum = INT_MAX;

        // Try every student as the initial distributor
        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] <= x)
                {
                    count++;
                }
            }

            // Minimum count.
            // <= gives highest ID in case of tie.
            if (count <= minimum)
            {
                minimum = count;
                ans = i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
