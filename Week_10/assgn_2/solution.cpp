#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> w(n);
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            total += w[i];
        }

        // dp[i] = maximum weight obtainable from books 0...i
        vector<long long> dp(n);

        dp[0] = w[0];

        if (n >= 2)
            dp[1] = max(w[0], w[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + w[i]);
        }

        double percentage = (double)dp[n - 1] * 100.0 / total;

        cout << fixed << setprecision(2) << percentage << "%\n";
    }

    return 0;
}
