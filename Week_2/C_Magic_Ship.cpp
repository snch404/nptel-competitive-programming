// Ctrl + Shift +B -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    ll n;
    cin >> n;

    string s;
    cin >> s;

    // Prefix displacement due to wind
    vll dx(n + 1, 0), dy(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        dx[i + 1] = dx[i];
        dy[i + 1] = dy[i];

        if (s[i] == 'U')
            dy[i + 1]++;
        else if (s[i] == 'D')
            dy[i + 1]--;
        else if (s[i] == 'L')
            dx[i + 1]--;
        else
            dx[i + 1]++;
    }

    ll lo = 0;
    ll hi = (abs(ex - sx) + abs(ey - sy)) * n;
    ll ans = -1;

    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;

        ll fullCycles = mid / n;
        ll remDays = mid % n;

        ll x = sx + fullCycles * dx[n] + dx[remDays];
        ll y = sy + fullCycles * dy[n] + dy[remDays];

        ll dist = abs(ex - x) + abs(ey - y);

        if (dist <= mid)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}