#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabcbb";
    unordered_map<char, int> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        freq[c]++;

        while (freq[c] > 1) {
            freq[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength;
    return 0;
}

int freq() {
    string s = "aaabbcc";
    int k = 2;
    unordered_map<char, int> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        freq[c]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength;
    return 0;
}