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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vi visited(n + 1, -1);
        vi ans(n + 1);

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == -1)
            {

                vi cycle;
                int cur = i;

                while (visited[cur] == -1)
                {
                    visited[cur] = 1;
                    cycle.push_back(cur);
                    cur = arr[cur];
                }

                int sz = cycle.size();

                for (int x : cycle)
                {
                    ans[x] = sz;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
