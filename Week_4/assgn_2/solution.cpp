#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    visited[i][j] = true;

    int cnt = 1;
    for (auto &dir : directions)
    {
        int ni = i + dir[0];
        int nj = j + dir[1];

        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size() || visited[ni][nj] == true || grid[ni][nj] == 0)
            continue;
        cnt += dfs(ni, nj, grid, visited);
    }

    return cnt;
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
        int m, n, x;
        cin >> m >> n >> x;

        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        int mxcnt = 0;
        int cnt = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    cnt = dfs(i, j, grid, visited);
                    mxcnt = max(cnt, mxcnt);
                }
            }
        }

        cout << (mxcnt >= 8 * x ? "Yes" : "No") << endl;
    }
    return 0;
}
