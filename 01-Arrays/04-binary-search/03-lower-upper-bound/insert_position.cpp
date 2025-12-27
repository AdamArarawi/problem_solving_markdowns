#include <bits/stdc++.h>
using namespace std;


int upperB(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int result = nums.size();;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (target < nums[mid]) {
            result = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return result;
}

int lowerB(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int result = nums.size();;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (target <= nums[mid]) {
            result = mid;
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
    int upper = upperB(nums, 2);
    int insert_position = lowerB(nums, 2);
    nums.insert(nums.begin() + insert_position, 2);
    int count = upperB(nums, 2) - lowerB(nums, 2);


    return 0;
}