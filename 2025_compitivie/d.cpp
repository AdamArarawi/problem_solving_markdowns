#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int stars = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < stars * 2 - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
        stars--;
    }

    return 0;
}