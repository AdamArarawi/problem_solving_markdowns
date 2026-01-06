#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int baseValue; // قيمة الخلايا المسموح المرور عليها

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (!valid(nx, ny))
            continue;
        if (visited[nx][ny])
            continue;

        // ⭐ شرط الدخول (غيره حسب المسألة)
        if (grid[nx][ny] != baseValue)
            continue;

        dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int sr, sc;
    cin >> sr >> sc;

    baseValue = grid[sr][sc]; // نقطة البداية
    dfs(sr, sc);

    return 0;
}
