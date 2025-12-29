#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int color;
int originColor;

void dfs(int sr, int sc)
{
    if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() || grid[sr][sc] != originColor)
    {
        return;
    }

    grid[sr][sc] = color;

    dfs(sr - 1, sc);
    dfs(sr + 1, sc);
    dfs(sr, sc + 1);
    dfs(sr, sc - 1);
}

int main()
{
    int r = 3, c = 3, sr, sc;
    cin >> sr >> sc >> color;

    grid.assign(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            cin >> grid[i][j];
            if (i == sr && sc == j)
            {
                originColor = grid[i][j];
            }
        }
    }

    dfs(sr, sc);
    cout << "\n";

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
