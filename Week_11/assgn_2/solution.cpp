#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{

    int n;
    cin >> n;

    vector<long long> metric(n + 2, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> metric[i];
    }

    // dp[l][r] stores the max score for interval strictly between l and r
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

    // length is the distance between l and r
    for (int len = 2; len <= n + 1; len++)
    {
        for (int l = 0; l <= n + 1 - len; l++)
        {
            int r = l + len;
            for (int k = l + 1; k < r; k++)
            {
                long long score = metric[l] * metric[k] * metric[r];
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + score);
            }
        }
    }

    cout << dp[0][n + 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}