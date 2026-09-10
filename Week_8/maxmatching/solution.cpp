#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

class MaxFlow
{
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d;
    vector<ii> parent;

    bool BFS(int s, int t)
    {
        d.assign(V, -1);
        parent.assign(V, {-1, -1});

        queue<int> q;
        q.push(s);
        d[s] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;

            for (int idx : AL[u])
            {
                auto &[v, cap, flow] = EL[idx];

                if (cap - flow > 0 && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    parent[v] = {u, idx};
                    q.push(v);
                }
            }
        }

        return d[t] != -1;
    }

    ll sendFlow(int s, int t, ll f = INF)
    {
        if (s == t)
            return f;

        auto [u, idx] = parent[t];

        auto &[v, cap, flow] = EL[idx];

        ll pushed = sendFlow(s, u, min(f, cap - flow));

        flow += pushed;
        get<2>(EL[idx ^ 1]) -= pushed;

        return pushed;
    }

public:
    MaxFlow(int n)
    {
        V = n;
        AL.assign(V, {});
    }

    void addEdge(int u, int v, ll capacity)
    {
        EL.emplace_back(v, capacity, 0);
        AL[u].push_back(EL.size() - 1);

        EL.emplace_back(u, 0, 0);
        AL[v].push_back(EL.size() - 1);
    }

    ll edmondsKarp(int s, int t)
    {
        ll maxFlow = 0;

        while (BFS(s, t))
        {
            ll flow = sendFlow(s, t);

            if (flow == 0)
                break;

            maxFlow += flow;
        }

        return maxFlow;
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

    int boys, girls;

    cin >> boys;

    vector<int> B(boys);
    for (int i = 0; i < boys; i++)
        cin >> B[i];

    cin >> girls;

    vector<int> G(girls);
    for (int i = 0; i < girls; i++)
        cin >> G[i];

    int source = 0;
    int boyStart = 1;
    int girlStart = boys + 1;
    int sink = boys + girls + 1;

    MaxFlow mf(boys + girls + 2);

    // Boy -> Girl edges
    for (int i = 0; i < boys; i++)
    {
        for (int j = 0; j < girls; j++)
        {
            if (abs(B[i] - G[j]) <= 1)
            {
                mf.addEdge(boyStart + i, girlStart + j, 1);
            }
        }
    }

    // Source -> Boys
    for (int i = 0; i < boys; i++)
    {
        mf.addEdge(source, boyStart + i, 1);
    }

    // Girls -> Sink
    for (int j = 0; j < girls; j++)
    {
        mf.addEdge(girlStart + j, sink, 1);
    }

    cout << mf.edmondsKarp(source, sink) << '\n';

    return 0;
}
