#include <bits/stdc++.h>
using namespace std;

int searchRotatedArray(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return nums[l];
}

int main() {
    vector<int> nums = { 3,4,5,1,2 };
    cout << searchRotatedArray(nums);
    return 0;
}
