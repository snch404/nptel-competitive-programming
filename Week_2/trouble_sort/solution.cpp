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

    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;

        vi even, odd;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (i % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        sort(all(even));
        sort(all(odd));

        int ans = -1;

        int e = even.size();
        int o = odd.size();

        for (int i = 0; i < e; i++)
        {
            // compare even[i] with odd[i]
            if (i < o && even[i] > odd[i])
            {
                ans = 2 * i;
                break;
            }

            // compare odd[i] with even[i+1]
            if (i < o && i + 1 < e && odd[i] > even[i + 1])
            {
                ans = 2 * i + 1;
                break;
            }
        }

        cout << "Case #" << tc << ": ";
        if (ans == -1)
            cout << "OK\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
