// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

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
        string s;
        int K;
        cin >> s >> K;

        int n = s.size();
        vector<int> start(n, 0);

        int active = 0;
        int ans = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            if (i >= K)
                active ^= start[i - K];

            bool isMinus = ((s[i] == '-') ^ active);

            if (isMinus)
            {
                if (i + K > n)
                {
                    ok = false;
                    break;
                }
                ans++;
                active ^= 1;
                start[i] = 1;
            }
        }

        cout << "Case #" << tc << ": ";
        if (ok)
            cout << ans << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
