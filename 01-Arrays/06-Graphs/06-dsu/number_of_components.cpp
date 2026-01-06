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
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    int connected_components = 0;

    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            connected_components += 1;
        }
    }
    cout << connected_components;

    return 0;
}
