#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int dp[10001];
int solve(int n)
{
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i;
        ans = max(ans, i * j + solve(i) + solve(j));
    }
    return dp[n] = ans;
}
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

    memset(dp, -1, sizeof(dp));
    dp[1] = 0;

    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
