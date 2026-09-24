// Frog 1

// There are N stones, numbered 1, 2, ..., N. For each i (1 ≤ i ≤ N), the height of Stone i is hi.

// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

// - If the frog is currently on Stone i, he can jump to Stone i+1 or Stone i+2. Here, a cost of |hi − hj| is incurred, where j is the stone to land on.

// Find the minimum possible total cost incurred before the frog reaches Stone N.

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h;
vector<int> memo;

int solve(int i)
{
    // Base cases
    if (i == 1)
        return 0;

    if (i == 2)
        return abs(h[2] - h[1]);

    // Already computed
    if (memo[i] != -1)
        return memo[i];

    int jump1 = solve(i - 1) + abs(h[i] - h[i - 1]);
    int jump2 = solve(i - 2) + abs(h[i] - h[i - 2]);

    return memo[i] = min(jump1, jump2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    h.resize(n + 1);
    memo.assign(n + 1, -1);

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << solve(n) << endl;

    return 0;
}
