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

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<vi> womenPref(N + 1, vi(N));
        vector<vi> menPref(N + 1, vi(N));

        // rank[w][m] = preference rank of man m for woman w
        // Smaller value = more preferred
        vector<vi> rank(N + 1, vi(N + 1));

        // Women's preferences
        for (int i = 0; i < N; i++)
        {
            int woman;
            cin >> woman;

            for (int j = 0; j < N; j++)
            {
                cin >> womenPref[woman][j];
                rank[woman][womenPref[woman][j]] = j;
            }
        }

        // Men's preferences
        for (int i = 0; i < N; i++)
        {
            int man;
            cin >> man;

            for (int j = 0; j < N; j++)
                cin >> menPref[man][j];
        }

        // womanPartner[w] = current partner of woman w
        // manPartner[m] = current partner of man m
        vector<int> womanPartner(N + 1, 0);
        vector<int> manPartner(N + 1, 0);

        // nextProposal[m] = next woman in preference list
        vector<int> nextProposal(N + 1, 0);

        queue<int> freeMen;

        for (int i = 1; i <= N; i++)
            freeMen.push(i);

        while (!freeMen.empty())
        {
            int man = freeMen.front();
            freeMen.pop();

            int woman = menPref[man][nextProposal[man]];
            nextProposal[man]++;

            if (womanPartner[woman] == 0)
            {
                womanPartner[woman] = man;
                manPartner[man] = woman;
            }
            else
            {
                int current = womanPartner[woman];

                if (rank[woman][man] < rank[woman][current])
                {
                    womanPartner[woman] = man;
                    manPartner[man] = woman;

                    manPartner[current] = 0;
                    freeMen.push(current);
                }
                else
                {
                    freeMen.push(man);
                }
            }
        }

        for (int man = 1; man <= N; man++)
            cout << man << " " << manPartner[man] << "\n";
    }

    return 0;
}