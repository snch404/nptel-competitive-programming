#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v)
    {
        parent[find(v)] = find(u);
    }

    bool hasSupervisor(int v)
    {
        return parent[v] != v;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    // Qualifications are not needed.
    // The problem guarantees that every given application
    // already has a qualified supervisor.
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
    }

    int m;
    cin >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;

        edges.push_back({cost, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    int answer = 0;
    int edgesUsed = 0;

    for (auto [cost, u, v] : edges)
    {

        if (edgesUsed == n - 1)
            break;

        // No cycle AND v does not already have a supervisor
        if (dsu.find(u) != dsu.find(v) &&
            dsu.find(v) == v)
        {

            answer += cost;
            edgesUsed++;

            dsu.unite(u, v);
        }
    }

    if (edgesUsed == n - 1)
        cout << answer;
    else
        cout << -1;
}