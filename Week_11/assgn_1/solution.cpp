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

        vi cash_bag(n);
        int total = 0;

        for (int &x : cash_bag)
        {
            cin >> x;
            total += x;
        }

        // Equal partition is impossible if total is odd
        if (total % 2 != 0)
        {
            cout << "False\n";
            continue;
        }

        int target = total / 2;

        // dp[s] = whether we can form sum s
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int money : cash_bag)
        {
            // Traverse backwards so each bill is used only once
            for (int s = target; s >= money; s--)
            {
                dp[s] = dp[s] || dp[s - money];
            }
        }

        cout << (dp[target] ? "True" : "False") << '\n';
    }

    return 0;
}