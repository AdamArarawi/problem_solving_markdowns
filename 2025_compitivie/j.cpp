#include <bits/stdc++.h>
using namespace std;

int is_digits(string &str)
{
    if (str.empty())
        return -1;

    int result = 0;
    for (char ch : str)
    {
        if (ch < '0' || ch > '9')
            return -1;
        result = result * 10 + (ch - '0');
    }
    if (result < 0 || result > 255)
        return -1;

    return result;
}

int main()
{
    string s;
    cin >> s;

    int left = 0;
    int parts = 0;

    for (int i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || s[i] == '.')
        {
            string part = s.substr(left, i - left);
            if (is_digits(part) == -1)
            {
                cout << 0;
                return 0;
            }
            parts++;
            left = i + 1;
        }
    }

    if (parts == 4)
        cout << 1;
    else
        cout << 0;

    return 0;
}
