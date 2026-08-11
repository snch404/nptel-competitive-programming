#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> parent;
vector<int> rankv;

int findP(int i)
{
    if (parent[i] == i)
        return i;

    return parent[i] = findP(parent[i]);
}

void Union(int x, int y)
{
    int xp = findP(x);
    int yp = findP(y);

    if (xp == yp)
        return;

    if (rankv[xp] > rankv[yp])
        parent[yp] = xp;
    else if (rankv[yp] > rankv[xp])
        parent[xp] = yp;
    else
    {
        parent[yp] = xp;
        rankv[xp]++;
    }
}

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
        int n, x, y, f;
        cin >> n >> x >> y >> f;

        parent.resize(n + 1);
        rankv.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        while (f--)
        {
            int s, d;
            ll fn;

            cin >> s >> d >> fn;

            Union(s, d);
        }

        if (findP(x) == findP(y))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}