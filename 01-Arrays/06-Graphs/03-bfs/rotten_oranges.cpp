#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int minutes = 0;

    while (!q.empty())
    {
        int sz = q.size();
        bool spread = false;

        for (int i = 0; i < sz; i++)
        {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    spread = true;
                }
            }
        }

        if (spread)
            minutes++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << minutes;
    return 0;
}
