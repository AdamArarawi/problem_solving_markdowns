#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, type, weight;
    cin >> n >> m >> type >> weight;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w = 1;
        cin >> u >> v;
        if (weight)
            cin >> w;

        if (type == 0)
        {
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        else
        {
            graph[u].push_back({v, w});
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        for (auto &edge : graph[i])
        {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << '\n';
    }

    return 0;
}
