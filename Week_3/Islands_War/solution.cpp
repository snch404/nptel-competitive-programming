#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> requests;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        requests.push_back({a, b});
    }

    sort(all(requests), comp);

    int ans = 0;
    int lastBridge = -1;

    for (auto request : requests)
    {
        if (lastBridge >= request.first)
            continue;

        lastBridge = request.second - 1;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}