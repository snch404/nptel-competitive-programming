#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using edge = tuple<int, ll, ll>; // (to, capacity, flow)

class Dinic
{
private:
    int V;
    vector<edge> EL;
    vector<vector<int>> AL;

    vector<int> d, p, last;

    bool BFS(int s, int t)
    {
        d.assign(V, -1);
        d[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;

            for (int idx : AL[u])
            {
                auto [v, cap, flow] = EL[idx];

                if (d[v] == -1 && cap - flow > 0)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        return d[t] != -1;
    }

    ll DFS(int u, int t, ll f)
    {
        if (u == t || f == 0)
            return f;

        for (int &i = last[u]; i < (int)AL[u].size(); i++)
        {
            int idx = AL[u][i];

            auto [v, cap, flow] = EL[idx];

            if (d[v] != d[u] + 1)
                continue;

            if (cap - flow <= 0)
                continue;

            ll pushed = DFS(v, t, min(f, cap - flow));

            if (pushed > 0)
            {
                get<2>(EL[idx]) += pushed;
                get<2>(EL[idx ^ 1]) -= pushed;

                return pushed;
            }
        }

        return 0;
    }

public:
    Dinic(int V) : V(V)
    {
        AL.assign(V, {});
    }

    void add_edge(int u, int v, ll cap, bool directed = true)
    {
        int idx = EL.size();

        EL.emplace_back(v, cap, 0);
        AL[u].push_back(idx);

        EL.emplace_back(u, directed ? 0 : cap, 0);
        AL[v].push_back(idx ^ 1);
    }

    ll maxflow(int s, int t)
    {
        ll mf = 0;

        while (BFS(s, t))
        {
            last.assign(V, 0);

            while (true)
            {
                ll pushed = DFS(s, t, LLONG_MAX);

                if (pushed == 0)
                    break;

                mf += pushed;
            }
        }

        return mf;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    Dinic dinic(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll cap;

        cin >> u >> v >> cap;

        // false = undirected edge
        dinic.add_edge(u - 1, v - 1, cap, false);
    }

    cout << dinic.maxflow(0, n - 1) << '\n';

    return 0;
}