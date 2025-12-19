#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int pref = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            count += freq[pref - k];
            freq[pref]++;
        }
        return count;
    }

    int maximumSizeSubarraySumEqualsK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = -1;
        int pref = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            if (freq.count(pref - k)) {
                int len = i - freq[pref - k];
                maxLen = max(len, maxLen);
            }
            if (!freq.count(pref)) {
                freq[pref] = i;
            }
        }
        return maxLen;
    }

    vector<int> runningSum(vector<int>& nums) {
        vector<int> pref(nums.size());
        pref[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        return pref;
    }

    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
        }

        int total = pref.back();

        for (int i = 0; i < n; i++) {

            int left = (i == 0) ? 0 : pref[i - 1];
            int right = total - pref[i];

            if (left == right) {
                return i;
            }
        }
        return -1;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suf(n);

        suf[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        int currProduct = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = currProduct * suf[i];
            currProduct *= nums[i];
        }
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suf(n);
        suf[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(prices[i], suf[i + 1]);
        }

        int maxProf = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxProf = max(suf[i] - prices[i], maxProf);
        }
        return maxProf;
    }
};

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
