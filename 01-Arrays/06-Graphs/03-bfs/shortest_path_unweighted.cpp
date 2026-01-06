#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent, dist;

void bfs(int node, int target)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    dist[node] = 0;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        if (n == target)
            break;

        for (int neighbor : graph[n])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = n;
                dist[neighbor] = dist[n] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, m, target;
    cin >> n >> m >> target;

    graph.assign(n, vector<int>());
    visited.assign(n, false);
    parent.assign(n, -1);
    dist.assign(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(0, target);

    if (dist[target] == -1)
    {
        cout << "No path\n";
        return 0;
    }

    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (int v : path)
        cout << v << " ";

    return 0;
}
