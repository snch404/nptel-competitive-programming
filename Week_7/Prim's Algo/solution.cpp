#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int s;
    cin >> s;

    while (s--)
    {

        int n;
        cin >> n;

        vector<vector<pair<int, int>>> AL(n);

        for (int i = 0; i < n; i++)
        {

            string name;
            int degree;

            cin >> name >> degree;

            while (degree--)
            {
                int v, w;
                cin >> v >> w;

                AL[i].push_back({v - 1, w});
            }
        }

        vector<int> taken(n, 0);

        // {weight, vertex}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        taken[0] = 1;

        for (auto [v, w] : AL[0])
            pq.push({w, v});

        int mst_cost = 0;
        int edges = 0;

        while (!pq.empty() && edges < n - 1)
        {

            auto [w, u] = pq.top();
            pq.pop();

            if (taken[u])
                continue;

            taken[u] = 1;
            mst_cost += w;
            edges++;

            for (auto [v, weight] : AL[u])
            {
                if (!taken[v])
                    pq.push({weight, v});
            }
        }

        cout << mst_cost << '\n';
    }

    return 0;
}
