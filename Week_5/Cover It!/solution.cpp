// Ctrl + Shift + B  -> Build (Compile solution.cpp)
// https://codeforces.com/problemset/problem/1176/E
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

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n + 1, 0);
        vector<int> color(n + 1);

        vector<int> even, odd;

        queue<int> q;
        q.push(1);
        visited[1] = 1;
        color[1] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (color[u] == 0)
                even.push_back(u);
            else
                odd.push_back(u);

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = 1;
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        if (even.size() <= odd.size())
        {
            cout << even.size() << '\n';
            for (int x : even)
                cout << x << " ";
        }
        else
        {
            cout << odd.size() << '\n';
            for (int x : odd)
                cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}
