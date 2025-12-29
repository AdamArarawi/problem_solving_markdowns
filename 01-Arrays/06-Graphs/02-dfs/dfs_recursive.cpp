#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfs(neighbor);
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
        graph[v].push_back(u); // إذا undirected
    }

    // مثال: DFS من node 0
    dfs(0);

    return 0;
}
