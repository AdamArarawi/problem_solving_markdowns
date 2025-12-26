#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (r == l) continue;

            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
            };
        }
    }
};