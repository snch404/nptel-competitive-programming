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
        int n;
        cin >> n;

        vector<pair<ll, ll>> locations(n);

        for (int i = 0; i < n; i++)
        {
            cin >> locations[i].first >> locations[i].second;
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<bool> visited(n, false);

        dist[0] = 0;

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            // Find the unvisited vertex with minimum distance
            int u = -1;

            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                {
                    u = j;
                }
            }

            visited[u] = true;
            ans += dist[u];

            // Update distances of all unvisited vertices
            for (int v = 0; v < n; v++)
            {
                if (!visited[v])
                {
                    ll cost = 2 * (abs(locations[u].first - locations[v].first) +
                                   abs(locations[u].second - locations[v].second));

                    dist[v] = min(dist[v], cost);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}