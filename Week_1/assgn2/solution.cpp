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
        int n, k;
        cin >> n >> k;

        vi arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());
        int count = 0;

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int j = i + 1;
            int l = n - 1;

            while (j < l)
            {
                int sum = arr[i] + arr[j] + arr[l];

                if (sum == k)
                {
                    count++;

                    int left = arr[j];
                    int right = arr[l];

                    while (j < l && arr[j] == left)
                        j++;
                    while (j < l && arr[l] == right)
                        l--;
                }
                else if (sum < k)
                {
                    j++;
                }
                else
                {
                    l--;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
