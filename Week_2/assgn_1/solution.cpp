// Ctrl + Shift + B  -> Build (Compile solution.cpp)
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
        int n, m;
        ll j;
        cin >> n >> m >> j;

        vector<ll> mat(n * m);
        for (int i = 0; i < n * m; i++)
            cin >> mat[i];

        int l = 0, h = (n * m) - 1;
        int c = 0;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (mat[mid] == j)
            {
                int r = mid / m;
                int cl = mid % m;
                cout << r + 1 << " " << cl + 1 << endl;
                c = 1;
                break;
            }
            else if (mat[mid] > j)
                h = mid - 1;
            else
                l = mid + 1;
        }

        if (c == 0)
            cout << -1 << " " << -1 << endl;
    }

    return 0;
}
