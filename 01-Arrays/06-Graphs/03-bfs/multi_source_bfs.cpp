#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> sources;
vector<bool> visited;
vector<int> dist;
int target;
void bfs()
{
    queue<int> q;

    for (int i : sources)
    {
        q.push(i);
        visited[i] = true;
        dist[i] = 0;
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int d : dist)
        cout << d << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>());
    visited.assign(n, false);
    dist.assign(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    cin >> k;
    sources.assign(k, -1);
    for (int i = 0; i < k; i++)
    {
        cin >> sources[i];
    }

    bfs();
    return 0;
}
