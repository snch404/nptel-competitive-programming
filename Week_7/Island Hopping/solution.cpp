#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define iii tuple<double, int, int>

const int MAXN = 64;

double X[MAXN], Y[MAXN], M[MAXN];
double inhabitants[MAXN];

class UnionFind
{
private:
    vi p, rank, setSize;
    int numSets;

public:
    UnionFind(int N)
    {
        p.resize(N);
        rank.assign(N, 0);
        setSize.assign(N, 1);

        for (int i = 0; i < N; i++)
            p[i] = i;

        numSets = N;
    }

    int findSet(int i)
    {
        if (p[i] == i)
            return i;

        return p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

    int numDisjointSets()
    {
        return numSets;
    }

    void unionSet(int i, int j)
    {

        if (isSameSet(i, j))
            return;

        int x = findSet(i);
        int y = findSet(j);

        // Union by size
        if (setSize[x] > setSize[y])
        {
            p[y] = x;
            inhabitants[x] += inhabitants[y];
            setSize[x] += setSize[y];
        }
        else
        {
            p[x] = y;
            inhabitants[y] += inhabitants[x];
            setSize[y] += setSize[x];
        }

        numSets--;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(2);

    int n, cases = 0;

    vector<iii> EL;

    while (true)
    {

        cin >> n;

        if (n == 0)
            break;

        // Read island information
        for (int i = 0; i < n; i++)
            cin >> X[i] >> Y[i] >> M[i];

        EL.clear();

        // Create all possible edges
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                double weight = hypot(
                    X[i] - X[j],
                    Y[i] - Y[j]);

                EL.push_back({weight, i, j});
            }
        }

        // Sort edges by distance
        sort(EL.begin(), EL.end());

        double sum = 0;
        double totalPopulation = 0;

        // Initialize inhabitants and total population
        for (int i = 0; i < n; i++)
        {
            inhabitants[i] = M[i];
            totalPopulation += M[i];
        }

        UnionFind UF(n);

        // Kruskal's algorithm
        for (auto &[weight, u, v] : EL)
        {

            if (UF.findSet(u) == UF.findSet(v))
                continue;

            int rootU = UF.findSet(u);
            int rootV = UF.findSet(v);
            int rootMain = UF.findSet(0);

            // Component containing u is connected to main island
            if (rootU == rootMain)
                sum += inhabitants[rootV] * weight;

            // Component containing v is connected to main island
            else if (rootV == rootMain)
                sum += inhabitants[rootU] * weight;

            UF.unionSet(u, v);
        }

        cases++;

        cout << "Island Group: " << cases
             << " Average " << sum / totalPopulation
             << "\n\n";
    }

    return 0;
}