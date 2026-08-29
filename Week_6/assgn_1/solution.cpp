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

        unordered_map<int, vector<pair<int, long long>>> adj;
        for (int i = 0; i < a; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>>
            pq;

        vector<long long> res(n + 1, INT_MAX);

        res[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            long long d = pq.top().first;
            int ngbr = pq.top().second;
            pq.pop();

            if (d > res[ngbr])
                continue;

            for (auto &v : adj[ngbr])
            {
                int adjNode = v.first;
                long long wt = v.second;

                if (d + wt < res[adjNode])
                {
                    res[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }

        long long mx = *max_element(res.begin() + 1, res.end());
        if (mx <= x * 60)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
