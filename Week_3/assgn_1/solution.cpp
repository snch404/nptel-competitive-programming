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

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int farthest = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > farthest)
            {
                cout << "NO\n";
                break;
            }

            farthest = max(farthest, i + a[i]);
        }

        if (farthest >= n - 1)
            cout << "YES\n";
    }

    return 0;
}

// DP (O(n^2))
// last[n-1] = true;

// for (int i = n-2; i >= 0; i--) {
//     for (int j = i+1; j <= min(n-1, i+a[i]); j++) {
//         if (last[j]) {
//             last[i] = true;
//             break;
//         }
//     }
// }