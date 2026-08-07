// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector
#define vll vector
#define all(x) (x).begin(), (x).end()

struct DSU
{
    vi<int> parent, rnk;

    DSU(int n)
    {
        parent.resize(n);
        rnk.assign(n, 0);
        iota(all(parent), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rnk[a] < rnk[b])
            swap(a, b);

        parent[b] = a;

        if (rnk[a] == rnk[b])
            rnk[a]++;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
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

    int n;
    cin >> n;

    DSU dsu(2 * n);

    int op, x, y;

    while (cin >> op >> x >> y)
    {

        if (op == 0)
            break;

        int ex = x + n;
        int ey = y + n;

        if (op == 1)
        { // set friends

            if (dsu.same(x, ey))
            {
                cout << -1 << '\n';
                continue;
            }

            dsu.unite(x, y);
            dsu.unite(ex, ey);
        }

        else if (op == 2)
        { // set enemies

            if (dsu.same(x, y))
            {
                cout << -1 << '\n';
                continue;
            }

            dsu.unite(x, ey);
            dsu.unite(y, ex);
        }

        else if (op == 3)
        { // are friends

            cout << dsu.same(x, y) << '\n';
        }

        else if (op == 4)
        { // are enemies

            cout << dsu.same(x, ey) << '\n';
        }
    }

    return 0;
}