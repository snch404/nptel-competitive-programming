#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

vi construct(int n, int c, int m)
{
    // Base case
    if (n == 1)
        return {m};

    // If c-1 is feasible for size n-1
    if (c - 1 >= n - 2 && c - 1 <= (n - 1) * n / 2 - 1)
    {
        vi arr = construct(n - 1, c - 1, m + 1);
        arr.insert(arr.begin(), m);
        return arr;
    }

    // Otherwise determine how much cost to spend here
    int x = c - (n * (n - 1)) / 2 + 1;

    vi arr = construct(n - 1, c - x, m + 1);

    reverse(arr.begin(), arr.begin() + (x - 1));

    arr.insert(arr.begin() + (x - 1), m);

    return arr;
}

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
        int n, c;
        cin >> n >> c;

        cout << "Case #" << tc << ": ";

        if (c < n - 1 || c > (n * (n + 1)) / 2 - 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vi ans = construct(n, c, 1);

        for (int x : ans)
            cout << x << " ";
        cout << '\n';
    }

    return 0;
}