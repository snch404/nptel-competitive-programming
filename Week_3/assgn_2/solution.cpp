#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

        int currSum = a[0];
        int bestSum = a[0];

        int start = 0, end = 0;
        int tempStart = 0;

        for (int i = 1; i < n; i++)
        {
            if (currSum + a[i] < a[i])
            {
                currSum = a[i];
                tempStart = i;
            }
            else
            {
                currSum += a[i];
            }

            if (currSum > bestSum)
            {
                bestSum = currSum;
                start = tempStart;
                end = i;
            }
        }

        for (int i = start; i <= end; i++)
        {
            cout << a[i];
            if (i != end)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}