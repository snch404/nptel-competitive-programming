// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

bool hasDiamond(int start, vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (visited[v])
            {
                return true;
            }

            visited[v] = true;
            q.push(v);
        }
    }

    return false;
}

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

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;

        vector<vector<int>> graph(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;

            while (k--)
            {
                int v;
                cin >> v;
                graph[i].push_back(v);
            }
        }

        bool answer = false;

        for (int i = 1; i <= n; i++)
        {
            if (hasDiamond(i, graph, n))
            {
                answer = true;
                break;
            }
        }

        cout << "Case #" << tc << ": "
             << (answer ? "Yes" : "No") << '\n';
    }

    return 0;
}
