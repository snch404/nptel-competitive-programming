#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

vi parent, sz;

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

bool unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];

    return true;
}

bool comp(const vi &a, const vi &b)
{
    return a[2] < b[2];
}

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
        int n, m;
        cin >> n >> m;

        vector<vi> edges(m, vi(3));

        for (int i = 0; i < m; i++)
        {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        sort(all(edges), comp);

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        ll ans = 0;
        int cnt = 0;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (unite(u, v))
            {
                ans += w;
                cnt++;

                if (cnt == n - 1)
                    break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}