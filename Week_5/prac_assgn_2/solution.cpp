// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int ans = 0;

vector<vector<int>> adj;
vector<int> v, d;

void dfs(int u, int parent, int depth, int flip[2])
{
    int parity = depth % 2;

    // Value of u after considering operations from its ancestors
    int current = v[u] ^ flip[parity];

    bool operated = false;

    // If u is incorrect, we must operate on u
    if (current != d[u])
    {
        ans++;
        flip[parity] ^= 1;
        operated = true;
    }

    // Process children
    for (int child : adj[u])
    {
        if (child == parent)
            continue;

        dfs(child, u, depth + 1, flip);
    }

    // Undo the effect before returning to the parent
    if (operated)
    {
        flip[parity] ^= 1;
    }
}

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

    adj.resize(n + 1);
    v.resize(n + 1);
    d.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    int flip[2] = {0, 0};

    dfs(1, 0, 0, flip);

    cout << ans << '\n';

    return 0;
}