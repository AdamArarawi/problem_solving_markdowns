#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    stack<int> st;
    st.push(node);

    while (!st.empty())
    {
        int n = st.top();
        st.pop();

        if (!visited[n])
        {
            visited[n] = true;
            cout << n << " ";

            for (int neighbor : graph[n])
            {
                if (!visited[neighbor])
                    st.push(neighbor);
            }
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
        graph[v].push_back(u); // إذا undirected
    }

    int num_component = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "Component " << num_component << ": ";
            dfs(i);
            cout << '\n';
            num_component++;
        }
    }

    dfs(0);

    return 0;
}
