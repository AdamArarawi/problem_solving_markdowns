#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> nums = { 1,2,3,4,2,1,5 };
    int k = 3;


    unordered_map<int, int> freq;


    int l = 0;
    int result = 0;

    for (int r = 0; r < nums.size(); r++) {
        freq[nums[r]]++;

        while (r - l + 1 > k)
        {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0) freq.erase(nums[l]);
            l++;
        }

        result = max(result, (int)freq.size());

    }
}
