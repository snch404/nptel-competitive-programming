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
        int n, q;
        cin >> n >> q;

        unordered_map<long long, int> first, last;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (first.find(x) == first.end())
                first[x] = i;

            last[x] = i;
        }

        int ans = 0;

        while (q--)
        {
            long long a, b;
            cin >> a >> b;

            if ((first.find(a) != first.end()) && (last.find(b) != last.end()) && (first[a] < last[b]))
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
