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
        int c, p, q;
        cin >> c;
        cin >> p >> q;

        vector<char> arr(p * q);
        vector<char> res(p * q);
        for (int i = 0; i < p * q; i++)
        {
            cin >> arr[i];
        }

        c = c % (p * q);
        if (c == 0)
            res = arr;
        else
        {
            for (int i = 0; i < p * q; i++)
                res[(i + c) % (p * q)] = arr[i];
        }
        int k = 0;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << res[k++];
                if (j != q - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
