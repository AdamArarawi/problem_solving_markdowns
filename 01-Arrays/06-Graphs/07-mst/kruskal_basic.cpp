#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto &e : edges)
    {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    DSU dsu(n);
    long long mst_cost = 0;
    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            mst_cost += e.w;
        }
    }

    cout << mst_cost << '\n';

    return 0;
}
