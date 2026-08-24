#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

vi parent;

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    // Store the queries
    vector<vector<int>> queries(Q);

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            queries[i] = {1, x};
        }
        else
        {
            int x, y;
            cin >> x >> y;
            queries[i] = {2, x, y};
        }
    }

    // Initially, every colour points to itself
    parent.resize(100001);

    for (int i = 1; i <= 100000; i++)
        parent[i] = i;

    vector<int> ans;

    // Process queries backwards
    for (int i = Q - 1; i >= 0; i--)
    {
        if (queries[i][0] == 1)
        {
            int x = queries[i][1];

            // A cube inserted with colour x
            // eventually becomes find(x)
            ans.push_back(find(x));
        }
        else
        {
            int x = queries[i][1];
            int y = queries[i][2];

            // x eventually becomes y
            parent[x] = find(y);
        }
    }

    // We processed backwards, so reverse the answers
    reverse(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << " ";

    cout << '\n';

    return 0;
}