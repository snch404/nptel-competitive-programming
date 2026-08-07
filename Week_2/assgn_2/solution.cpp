// Ctrl + Shift + B  -> Build (Compile solution.cpp)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<ll> client(n);

        for (int i = 0; i < n; i++)
            cin >> client[i];

        vector<ll> b(m);
        vector<int> c(m);

        for (int i = 0; i < m; i++)
            cin >> b[i];

        for (int i = 0; i < m; i++)
            cin >> c[i];

        // Expand the bonds according to their capacities
        vector<ll> bonds;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < c[i]; j++)
                bonds.push_back(b[i]);
        }

        sort(all(client));
        sort(all(bonds));

        ll invested = 0;
        ll loss = 0;

        for (int i = 0; i < n; i++)
        {
            invested += min(client[i], bonds[i]);
            loss += abs(client[i] - bonds[i]);
        }

        cout << invested << " " << loss << "\n";
    }

    return 0;
}