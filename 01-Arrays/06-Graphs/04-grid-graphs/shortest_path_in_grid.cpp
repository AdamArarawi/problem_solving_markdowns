#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> dist;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sr, int sc, int tr, int tc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    dist[sr][sc] = 0;

    int baseValue = grid[sr][sc];

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == tr && y == tc)
            return;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (!valid(nx, ny))
                continue;
            if (visited[nx][ny])
                continue;
            if (grid[nx][ny] != baseValue)
                continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            parent[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int sr, sc, tr, tc;
    cin >> sr >> sc;
    cin >> tr >> tc;

    bfs(sr, sc, tr, tc);

    if (dist[tr][tc] == -1)
    {
        cout << "No path\n";
        return 0;
    }

    vector<pair<int, int>> path;
    int x = tr, y = tc;
    while (x != -1)
    {
        path.push_back({x, y});
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());

    cout << "Shortest distance = " << dist[tr][tc] << "\n";
    cout << "Path:\n";
    for (auto [r, c] : path)
        cout << "(" << r << ", " << c << ") ";

    cout << "\n";
    return 0;
}
