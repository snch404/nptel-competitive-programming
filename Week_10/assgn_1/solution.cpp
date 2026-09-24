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

    // dp[x] = number of ways to climb x stairs
    while (t--)
    {
        int x;
        ll y;
        cin >> x >> y;

        ll dp[51];

        dp[0] = 1 % y;
        dp[1] = 1 % y;

        for (int i = 2; i <= x; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % y;
        }

        cout << dp[x] << '\n';
    }

    return 0;
}