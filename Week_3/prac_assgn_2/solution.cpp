#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

// Returns true if Ankita wins, false if Biswas wins
bool simulate(vi ank, vi bis, bool ankitaFirst)
{
    sort(all(ank));
    sort(all(bis));

    int i = ank.size() - 1;
    int j = bis.size() - 1;

    int st;
    bool ankitaTurn;

    // First move
    if (ankitaFirst)
    {
        st = ank[i--];
        ankitaTurn = false;
    }
    else
    {
        st = bis[j--];
        ankitaTurn = true;
    }

    while (true)
    {
        if (ankitaTurn)
        {
            // Find largest Ankita card > st
            while (i >= 0 && ank[i] <= st)
                i--;

            // Ankita cannot move
            if (i < 0)
                return false;

            st = ank[i--];
            ankitaTurn = false;
        }
        else
        {
            // Find largest Biswas card > st
            while (j >= 0 && bis[j] <= st)
                j--;

            // Biswas cannot move
            if (j < 0)
                return true;

            st = bis[j--];
            ankitaTurn = true;
        }
    }
}

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

        vi ank(n);
        for (int i = 0; i < n; i++)
            cin >> ank[i];

        int m;
        cin >> m;

        vi bis(m);
        for (int i = 0; i < m; i++)
            cin >> bis[i];

        // Case 1: Ankita starts
        bool ankitaWins = simulate(ank, bis, true);

        // Case 2: Biswas starts
        bool ankitaWinsIfBiswasStarts = simulate(ank, bis, false);

        cout << (ankitaWins ? "Ankita" : "Biswas") << '\n';
        cout << (ankitaWinsIfBiswasStarts ? "Ankita" : "Biswas") << '\n';
    }

    return 0;
}