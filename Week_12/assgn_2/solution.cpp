#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Direction vectors for moving up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// DFS function with memoization to find the longest increasing path
int dfs(int r, int c, int m, int n, const vector<vector<long long>> &grid, vector<vector<int>> &memo)
{
    if (memo[r][c] != -1)
        return memo[r][c];

    int max_len = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dx[i];
        int nc = c + dy[i];

        // Check boundary conditions and strictly increasing condition
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[r][c])
        {
            max_len = max(max_len, 1 + dfs(nr, nc, m, n, grid, memo));
        }
    }

    return memo[r][c] = max_len;
}

int getLongestIncreasingPath(int m, int n, const vector<vector<long long>> &grid)
{
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int max_path = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            max_path = max(max_path, dfs(i, j, m, n, grid, memo));
        }
    }

    return max_path;
}

void solve()
{
    int m, n;
    if (!(cin >> m >> n))
        return;

    // Read Your Grid (Row-Major Order)
    vector<vector<long long>> my_grid(m, vector<long long>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> my_grid[i][j];
        }
    }

    // Read Friend's Grid (Column-Major Order)
    vector<vector<long long>> friend_grid(m, vector<long long>(n));
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            cin >> friend_grid[i][j];
        }
    }

    int my_longest_path = getLongestIncreasingPath(m, n, my_grid);
    int friend_longest_path = getLongestIncreasingPath(m, n, friend_grid);

    if (my_longest_path > friend_longest_path)
    {
        cout << 1 << "\n";
    }
    else if (friend_longest_path > my_longest_path)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}
