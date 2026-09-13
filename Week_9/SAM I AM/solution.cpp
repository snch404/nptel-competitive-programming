#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Edge = tuple<int, ll, ll>;

const ll INF = 1e18;

class MaxFlow
{
private:
    int V;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<pair<int, int>> parent;

    bool bfs(int s, int t)
    {
        dist.assign(V, -1);
        parent.assign(V, {-1, -1});

        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;

            for (int idx : adj[u])
            {
                auto &[v, cap, flow] = edges[idx];

                if (cap - flow > 0 && dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    parent[v] = {u, idx};
                    q.push(v);
                }
            }
        }

        return dist[t] != -1;
    }

    ll sendFlow(int s, int t, ll f = INF)
    {
        if (s == t)
            return f;

        auto [u, idx] = parent[t];

        auto &[v, cap, flow] = edges[idx];

        ll pushed = sendFlow(s, u, min(f, cap - flow));

        flow += pushed;
        get<2>(edges[idx ^ 1]) -= pushed;

        return pushed;
    }

public:
    MaxFlow(int n)
    {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v, ll capacity)
    {
        edges.emplace_back(v, capacity, 0);
        adj[u].push_back(edges.size() - 1);

        edges.emplace_back(u, 0, 0);
        adj[v].push_back(edges.size() - 1);
    }

    ll maxFlow(int s, int t)
    {
        ll result = 0;

        while (bfs(s, t))
        {
            ll flow = sendFlow(s, t);

            if (flow == 0)
                break;

            result += flow;
        }

        return result;
    }

    vector<int> reachable(int s)
    {
        vector<int> visited(V, false);
        vector<int> result;

        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int idx : adj[u])
            {
                auto &[v, cap, flow] = edges[idx];

                if (cap - flow > 0 && !visited[v])
                {
                    visited[v] = true;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }

        return result;
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

    while (true)
    {
        int r, c, n;
        cin >> r >> c >> n;

        if (r == 0 && c == 0 && n == 0)
            break;

        int source = 0;
        int sink = r + c + 1;

        MaxFlow mf(r + c + 2);

        // Row -> Column edges
        for (int i = 0; i < n; i++)
        {
            int row, col;
            cin >> row >> col;

            mf.addEdge(row, r + col, 1);
        }

        // Source -> Rows
        for (int row = 1; row <= r; row++)
        {
            mf.addEdge(source, row, 1);
        }

        // Columns -> Sink
        for (int col = 1; col <= c; col++)
        {
            mf.addEdge(r + col, sink, 1);
        }

        // Maximum matching
        int matching = mf.maxFlow(source, sink);

        cout << matching << " ";

        // Find vertices reachable in residual graph
        vector<int> reachable = mf.reachable(source);

        // Minimum vertex cover:
        // Unreachable rows + reachable columns

        for (int row = 1; row <= r; row++)
        {
            if (find(reachable.begin(), reachable.end(), row) == reachable.end())
                cout << "r" << row << " ";
        }

        for (int col = 1; col <= c; col++)
        {
            if (find(reachable.begin(), reachable.end(), r + col) != reachable.end())
                cout << "c" << col << " ";
        }

        cout << '\n';
    }

    return 0;
}