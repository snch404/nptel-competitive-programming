#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
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
        int C, L, S;
        cin >> C >> L >> S;

        // Chargers
        vi charger(C);
        for (int &x : charger)
            cin >> x;

        // Laptops
        vi laptop(L);
        for (int &x : laptop)
            cin >> x;

        // Tolerance
        vi tolerance(L);
        for (int &x : tolerance)
            cin >> x;

        // Students
        vi H(S), CF(S), R(S);

        for (int &x : H)
            cin >> x;

        for (int &x : CF)
            cin >> x;

        for (int &x : R)
            cin >> x;

        // ----------------------------------------
        // Find maximum number of working laptops
        // ----------------------------------------

        vector<pair<int, int>> laptops;

        for (int i = 0; i < L; i++)
        {
            int low = laptop[i];
            int high = laptop[i] + tolerance[i];

            laptops.push_back({high, low});
        }

        sort(all(laptops));

        multiset<int> chargers(all(charger));

        int working = 0;

        for (auto p : laptops)
        {
            int high = p.first;
            int low = p.second;

            auto it = chargers.lower_bound(low);

            if (it != chargers.end() && *it <= high)
            {
                working++;
                chargers.erase(it);
            }
        }

        if (working == 0)
        {
            cout << -1 << '\n';
            continue;
        }

        int k = min(working, S);

        // ----------------------------------------
        // Find min and max values
        // ----------------------------------------

        int minH = *min_element(all(H));
        int maxH = *max_element(all(H));

        int minC = *min_element(all(CF));
        int maxC = *max_element(all(CF));

        int minR = *min_element(all(R));
        int maxR = *max_element(all(R));

        // ----------------------------------------
        // Calculate student scores
        // pair = {score, student index}
        // ----------------------------------------

        vector<pair<long double, int>> students;

        for (int i = 0; i < S; i++)
        {
            long double h = 0, c = 0, r = 0;

            if (maxH != minH)
                h = (long double)(H[i] - minH) / (maxH - minH);

            if (maxC != minC)
                c = (long double)(CF[i] - minC) / (maxC - minC);

            if (maxR != minR)
                r = (long double)(R[i] - minR) / (maxR - minR);

            long double score = 0.5L * h + 0.3L * c + 0.2L * r;

            students.push_back({score, i});
        }

        // Highest score first.
        // If scores are equal, lower index first.
        sort(students.begin(), students.end(),
             [](const pair<long double, int> &a,
                const pair<long double, int> &b)
             {
                 if (a.first != b.first)
                     return a.first > b.first;

                 return a.second < b.second;
             });

        // ----------------------------------------
        // Select best k students
        // ----------------------------------------

        ll answer = 0;

        for (int i = 0; i < k; i++)
        {
            int student = students[i].second;
            answer += H[student];
        }

        cout << answer << '\n';
    }

    return 0;
}