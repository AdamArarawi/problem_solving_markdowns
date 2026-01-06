#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int newColor, originColor;
int r, c;

void dfs(int x, int y)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
        return;
    if (grid[x][y] != originColor)
        return;

    grid[x][y] = newColor;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main()
{
    cin >> r >> c;
    grid.assign(r, vector<int>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    int sr, sc;
    cin >> sr >> sc >> newColor;

    originColor = grid[sr][sc];
    if (originColor != newColor)
        dfs(sr, sc);

    for (auto &row : grid)
    {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }
}
