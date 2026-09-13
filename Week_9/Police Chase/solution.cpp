#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

class max_flow
{
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d;
    vector<ii> p;

    bool BFS(int s, int t)
    {
        d.assign(V, -1);
        d[s] = 0;

        queue<int> q;
        q.push(s);

        p.assign(V, {-1, -1});

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;

            for (auto idx : AL[u])
            {
                auto &[v, cap, flow] = EL[idx];

                if (cap - flow > 0 && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    p[v] = {u, idx};
                    q.push(v);
                }
            }
        }

        return d[t] != -1;
    }

    ll send_one_flow(int s, int t, ll f = INF)
    {
        if (s == t)
            return f;

        auto [u, idx] = p[t];

        auto &[v, cap, flow] = EL[idx];

        ll pushed = send_one_flow(s, u, min(f, cap - flow));

        flow += pushed;
        get<2>(EL[idx ^ 1]) -= pushed;

        return pushed;
    }

public:
    max_flow(int n)
    {
        V = n;
        AL.assign(V, {});
    }

    void add_edge(int u, int v, ll w, bool directed = true)
    {
        EL.emplace_back(v, w, 0);
        AL[u].push_back(EL.size() - 1);

        EL.emplace_back(u, directed ? 0 : w, 0);
        AL[v].push_back(EL.size() - 1);
    }

    ll edmonds_karp(int s, int t)
    {
        ll maxf = 0;

        while (BFS(s, t))
        {
            ll f = send_one_flow(s, t);

            if (f == 0)
                break;

            maxf += f;
        }

        return maxf;
    }

    vi reachable_set(int s)
    {
        d.assign(V, -1);
        d[s] = 0;

        vi reachable;
        queue<int> q;

        q.push(s);
        reachable.push_back(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto idx : AL[u])
            {
                auto &[v, cap, flow] = EL[idx];

                if (cap - flow > 0 && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                    reachable.push_back(v);
                }
            }
        }

        return reachable;
    }

    bool isEdge(int u, int v)
    {
        for (auto idx : AL[u])
        {
            if (get<0>(EL[idx]) == v)
                return true;
        }

        return false;
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

    int n, m;
    cin >> n >> m;

    max_flow maxf(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        maxf.add_edge(u, v, 1, false);
    }

    cout << maxf.edmonds_karp(1, n) << '\n';

    vi scomp = maxf.reachable_set(1);
    vi tcomp;

    for (int i = 1; i <= n; i++)
    {
        if (find(scomp.begin(), scomp.end(), i) == scomp.end())
            tcomp.push_back(i);
    }

    for (int u : scomp)
    {
        for (int v : tcomp)
        {
            if (maxf.isEdge(u, v))
                cout << u << " " << v << '\n';
        }
    }

    return 0;
}
