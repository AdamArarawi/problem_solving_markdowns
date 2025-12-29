#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool has_cycle = false;

void dfs_cycle(int node, int parent)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs_cycle(neighbor, node);
        }
        else if (neighbor != parent)
        {
            has_cycle = true;
        }
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
        graph[v].push_back(u); // undirected
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs_cycle(i, -1);
    }

    if (has_cycle)
        cout << "Graph has a cycle\n";
    else
        cout << "Graph has no cycle\n";

    return 0;
}
