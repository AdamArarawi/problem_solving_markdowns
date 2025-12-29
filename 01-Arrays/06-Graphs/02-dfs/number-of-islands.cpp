#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> grid;

void dfs(int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] || grid[r][c] == 0)
    {
        return;
    }

    visited[r][c] = true;

    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}

int main()
{
    int r, c;
    cin >> r >> c;

    grid.assign(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    visited.assign(r, vector<bool>(c, false));

    int num_islands = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j);
                num_islands++;
            }
        }
    }

    cout << num_islands << endl;

    return 0;
}
