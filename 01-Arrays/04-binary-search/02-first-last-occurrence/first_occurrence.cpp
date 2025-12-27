#include <bits/stdc++.h>
using namespace std;


int first_occurrence(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            result = mid;
            r = mid - 1;
        }
        else if (nums[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 1,2,2,2,3 };
    cout << first_occurrence(nums, 2);
    return 0;
}