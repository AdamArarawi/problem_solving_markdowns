#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    getline(cin, s);
    string curr = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size() - 1)
        {
            if (i == s.size() - 1)
            {
                curr.push_back(s[i]);
            }
            for (int j = curr.size() - 1; j >= 0; j--)
            {
                cout << curr[j];
            }
            cout << " ";
            curr = "";
        }
        else
        {
            curr.push_back(s[i]);
        }
    }
    return 0;
}