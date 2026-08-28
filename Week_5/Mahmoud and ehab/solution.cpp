// https://codeforces.com/problemset/problem/862/B
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
long long cnt[2];

void dfs(int u, int c)
{
    color[u] = c;
    cnt[c]++;

    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            dfs(v, 1 - c);
        }
    }
}

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

    adj.resize(n + 1);
    color.assign(n + 1, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << cnt[0] * cnt[1] - (n - 1) << '\n';

    return 0;
}
