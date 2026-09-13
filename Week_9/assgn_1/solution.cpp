#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, M, K;

vector<pair<ll, ll>> ship;
vector<pair<ll, ll>> planet;
vector<ll> speed;

vector<int> matchPlanet;
vector<bool> vis;

bool dfs(int u, ll T)
{
    for (int v = 0; v < M; v++)
    {
        if (vis[v])
            continue;

        ll dx = ship[u].first - planet[v].first;
        ll dy = ship[u].second - planet[v].second;

        ll dist = dx * dx + dy * dy;

        // Time = ceil(dist / speed^2)
        ll s2 = speed[u] * speed[u];
        ll time = (dist + s2 - 1) / s2;

        if (time > T)
            continue;

        vis[v] = true;

        if (matchPlanet[v] == -1 || dfs(matchPlanet[v], T))
        {
            matchPlanet[v] = u;
            return true;
        }
    }

    return false;
}

bool possible(ll T)
{
    matchPlanet.assign(M, -1);

    int matching = 0;

    for (int i = 0; i < N; i++)
    {
        vis.assign(M, false);

        if (dfs(i, T))
            matching++;
    }

    return matching >= K;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> N >> M >> K;

        ship.resize(N);
        planet.resize(M);
        speed.resize(N);

        for (int i = 0; i < N; i++)
            cin >> ship[i].first >> ship[i].second;

        for (int i = 0; i < M; i++)
            cin >> planet[i].first >> planet[i].second;

        for (int i = 0; i < N; i++)
            cin >> speed[i];

        // Find maximum possible travel time
        ll high = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                ll dx = ship[i].first - planet[j].first;
                ll dy = ship[i].second - planet[j].second;

                ll dist = dx * dx + dy * dy;
                ll s2 = speed[i] * speed[i];

                ll time = (dist + s2 - 1) / s2;

                high = max(high, time);
            }
        }

        if (!possible(high))
        {
            cout << -1 << '\n';
            continue;
        }

        ll low = 0;

        while (low < high)
        {
            ll mid = low + (high - low) / 2;

            if (possible(mid))
                high = mid;
            else
                low = mid + 1;
        }

        cout << low * 60 << '\n';
    }

    return 0;
}