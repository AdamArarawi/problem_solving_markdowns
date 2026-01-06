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
    int n = 5;
    DSU dsu(n);

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    cout << dsu.same(0, 2) << "\n"; // 1
    cout << dsu.same(2, 4) << "\n"; // 0

    return 0;
}
