#include <bits/stdc++.h>
using namespace std;
void n_queens(int n, vector<int> &columns, int currRow)
{ // base condition
    if (currRow == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "(" << i << "," << columns[i] << ") ";
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        bool safe = true;
        for (int r = 0; r < currRow; r++)
        {
            if (columns[r] == col || abs(currRow - r) == abs(col - columns[r]))
            {
                safe = false;
                break;
            }
        }
        if (safe)
        {
            columns[currRow] = col;
            n_queens(n, columns, currRow + 1);
        }
    }
}
int main()
{
    int n = 8;
    vector<int> columns(n);
    n_queens(n, columns, 0);
    return 0;
}