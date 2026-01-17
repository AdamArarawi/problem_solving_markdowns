#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    if (s.empty())
        getline(cin, s);

    unordered_set<string> ill;
    string curr = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size() - 1)
        {
            if (i == s.size() - 1)
                curr.push_back(s[i]);

            ill.insert(curr);
            curr.clear();
        }
        else
        {
            curr.push_back(s[i]);
        }
    }

    string words;
    getline(cin, words);

    curr = "";
    int result = 0;

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == ' ' || i == words.size() - 1)
        {
            if (i == words.size() - 1)
                curr.push_back(words[i]);

            if (ill.find(curr) != ill.end())
                result++;

            curr.clear();
        }
        else
        {
            curr.push_back(words[i]);
        }
    }

    cout << result;
    return 0;
}
