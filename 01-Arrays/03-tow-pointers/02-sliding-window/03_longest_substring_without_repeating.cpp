#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabcbb";
    unordered_set<char> chars;
    int l = 0, maxLen = 0;

    for (int r = 0; r < s.size(); ++r) {
        while (chars.count(s[r])) {
            chars.erase(s[l]);     
            l++;
        }
        chars.insert(s[r]);
        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen << endl;
    return 0;
}
