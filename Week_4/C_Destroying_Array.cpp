#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

class DSU
{
    vi parent, sz;
    vector<ll> sum;

public:
    DSU(int n)
    {
        parent.assign(n + 1, -1);
        sz.assign(n + 1, 0);
        sum.assign(n + 1, 0);
    }

    void makeSet(int i, ll val)
    {
        parent[i] = i;
        sz[i] = 1;
        sum[i] = val;
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

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
    }

    ll getSum(int x)
    {
        return sum[find(x)];
    }
};

int main()
{
    fastio;

    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vi order(n);
    for (int i = 0; i < n; i++)
        cin >> order[i];

    reverse(all(order));

    DSU dsu(n);

    vi alive(n + 2, 0);
    vector<ll> ans;

    ll best = 0;
    ans.push_back(0);

    for (int x : order)
    {

        alive[x] = 1;

        dsu.makeSet(x, a[x]);

        if (x > 1 && alive[x - 1])
            dsu.unite(x, x - 1);

        if (x < n && alive[x + 1])
            dsu.unite(x, x + 1);

        best = max(best, dsu.getSum(x));

        ans.push_back(best);
    }

    ans.pop_back();

    reverse(all(ans));

    for (ll x : ans)
        cout << x << endl;

    return 0;
}