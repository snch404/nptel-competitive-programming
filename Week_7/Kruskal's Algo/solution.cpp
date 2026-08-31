#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool sameSet(int a, int b)
    {
        return find(a) == find(b);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {

        int n;
        cin >> n;

        // {weight, u, v}
        vector<tuple<int, int, int>> edges;

        for (int u = 0; u < n; u++)
        {

            string name;
            int degree;

            cin >> name >> degree;

            while (degree--)
            {
                int v, weight;
                cin >> v >> weight;

                edges.push_back({weight, u, v - 1});
            }
        }

        // Sort according to weight
        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int mstCost = 0;
        int edgesTaken = 0;

        for (auto [weight, u, v] : edges)
        {

            if (dsu.sameSet(u, v))
                continue;

            dsu.unite(u, v);

            mstCost += weight;
            edgesTaken++;

            if (edgesTaken == n - 1)
                break;
        }

        cout << mstCost << '\n';
    }

    return 0;
}