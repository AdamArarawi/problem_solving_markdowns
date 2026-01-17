#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int bit = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << bit;
            bit ^= 1;
        }
        cout << '\n';
    }

    return 0;
}
