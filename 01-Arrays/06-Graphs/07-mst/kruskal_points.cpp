#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

int main()
{
    int n, m, c_lib, c_road;
    cin >> n >> m >> c_lib >> c_road;

    if (c_road >= c_lib)
    {
        cout << 1LL * n * c_lib << "\n";
        return 0;
    }

    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        dsu.unite(x, y);
    }

    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            cost += c_lib + 1LL * (dsu.sz[i] - 1) * c_road;
        }
    }

    cout << cost << "\n";
    return 0;
}
