#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int lastDigitA = a.back() - '0';
    int lastDigitB = b.back() - '0';

    cout << lastDigitA * lastDigitB;

    return 0;
}