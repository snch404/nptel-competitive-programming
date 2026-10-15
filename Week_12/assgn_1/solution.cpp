#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the Minimum Edit Distance (Levenshtein Distance)
int minEditDistance(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();

    // dp[i][j] stores the edit distance between s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = i; // Deleting all characters from s1
    }
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = j; // Inserting all characters of s2
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            }
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // Delete
                                   dp[i][j - 1],    // Insert
                                   dp[i - 1][j - 1] // Replace
                               });
            }
        }
    }

    return dp[n][m];
}

void solve()
{
    long long n, m, a, x, y, z;
    if (!(cin >> n >> m >> a >> x >> y >> z))
        return;

    string s1, s2;
    cin >> s1 >> s2;

    long long changes = minEditDistance(s1, s2);
    long long total_cost = 0;

    if (changes <= x)
    {
        total_cost = changes * y;
    }
    else
    {
        total_cost = (x * y) + ((changes - x) * z);
    }

    long long net_profit = a - total_cost;
    cout << net_profit << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}
