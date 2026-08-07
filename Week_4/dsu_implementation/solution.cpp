// Ctrl + Shift + B  -> Build (Compile solution.cpp)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector
#define all(x) (x).begin(), (x).end()

class DSU
{
    vi<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x)
    {
        return sz[find(x)];
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

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--)
    {
        string op;
        int u, v;
        cin >> op >> u >> v;

        if (op == "union")
            dsu.unite(u, v);
        else
        {
            if (dsu.same(u, v))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}