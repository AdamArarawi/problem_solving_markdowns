#include <bits/stdc++.h>
using namespace std;

long long fib_memo(int n, vector<long long> &memo)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 50;
    vector<long long> memo(n + 1, -1);
    cout << fib_memo(n, memo);
    return 0;
}