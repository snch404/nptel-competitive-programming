// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

const double GOLDEN = (1 + sqrt(5.0)) / 2.0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        double a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        ll ans = 0;

        for (int b = b1; b <= b2; b++)
        {
            if (floor(GOLDEN * b) < a1 || floor((GOLDEN - 1) * b) > a2)
            {
                ans += (a2 - a1 + 1);
            }
            else
            {
                ans += max(0.0, a2 - floor(GOLDEN * b));
                ans += max(0.0, ceil((GOLDEN - 1) * b) - a1);
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}