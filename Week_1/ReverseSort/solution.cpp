#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int reversort(vector<int> &L)
{
    int cost = 0;

    for (int i = 0; i < L.size() - 1; i++)
    {
        int m = *min_element(L.begin() + i, L.end());

        auto x = find(L.begin(), L.end(), m);

        reverse(L.begin() + i, x + 1);

        cost += distance(L.begin(), x) - i + 1;
    }
    return cost;
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

    for (int c = 1; c <= T; c++)
    {
        int N;
        cin >> N;

        vector<int> L;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            L.push_back(num);
        }

        cout << "Case #" << c << ":" << reversort(L) << endl;
    }

    return 0;
}
