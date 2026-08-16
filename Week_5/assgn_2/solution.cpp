// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

int bfs(unordered_map<int, vector<int>> &adj, vector<int> &inDegree)
{
    queue<int> que;
    int res = 0;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        res++;
        for (int &v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                que.push(v);
        }
    }

    return res;
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
        int n, tOrder;
        cin >> n >> tOrder;
        int u, v;
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> adj;
        while (tOrder--)
        {
            cin >> v >> u;
            adj[u].push_back(v);
            inDegree[v]++;
        }

        int q = bfs(adj, inDegree);

        if (q == n)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
