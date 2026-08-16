// Ctrl + Shift + B  -> Build (Compile solution.cpp)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()

vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>> &board, queue<vector<int>> &que)
{
    int time = 0;
    while (!que.empty())
    {
        int sz = que.size();
        bool changed = false;
        while (sz--)
        {
            auto v = que.front();
            que.pop();

            int r = v[0];
            int c = v[1];
            for (auto &dir : directions)
            {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size())
                    continue;

                if (board[nr][nc] != 1)
                    continue;

                board[nr][nc] = 0;
                que.push({nr, nc});
                changed = true;
            }
        }
        if (changed)
            time += 2;
    }
    // If any mole is still above the surface
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
                return -1;
        }
    }
    return time;
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
        int p, q;
        cin >> p >> q;

        vector<vector<int>> board(p, vector<int>(q));
        queue<vector<int>> que;

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 0)
                {
                    que.push({i, j});
                }
            }
        }

        int res = bfs(board, que);
        cout << res << endl;
    }
    return 0;
}
