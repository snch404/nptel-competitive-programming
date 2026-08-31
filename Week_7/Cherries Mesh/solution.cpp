#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x], parent);
}

bool unite(int a, int b, vector<int> &parent)
{
    a = find(a, parent);
    b = find(b, parent);

    if (a == b)
        return false;

    parent[a] = b;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {

        int n, m;
        cin >> n >> m;

        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        int components = n;
        int blackUsed = 0;

        for (int i = 0; i < m; i++)
        {

            int u, v;
            cin >> u >> v;

            // Take this black edge only if it connects
            // two different components.
            if (unite(u, v, parent))
            {
                blackUsed++;
                components--;
            }
        }

        // Connect the remaining components using red edges.
        int answer = blackUsed + 2 * (components - 1);

        cout << "Case #" << tc << ": " << answer << '\n';
    }

    return 0;
}