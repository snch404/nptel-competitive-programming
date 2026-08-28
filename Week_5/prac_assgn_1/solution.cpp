#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> parent[i];

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int depth = 1;
        int current = i;

        while (parent[current] != -1)
        {
            current = parent[current];
            depth++;
        }

        ans = max(ans, depth);
    }

    cout << ans << endl;

    return 0;
}
