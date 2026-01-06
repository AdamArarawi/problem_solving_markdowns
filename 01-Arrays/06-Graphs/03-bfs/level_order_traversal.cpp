#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs_level_order(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();
        cout << "Level " << level << ": ";

        for (int i = 0; i < sz; i++)
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << '\n';
        level++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs_level_order(0);
    return 0;
}
