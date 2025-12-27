#include <bits/stdc++.h>
using namespace std;


int last_occurrence(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            result = mid;
            l = mid + 1;
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

int count_occurrences(vector<int>& nums, int target) {
    int first = first_occurrence(nums, target);
    if (first == -1) return 0;

    int last = last_occurrence(nums, target);
    return last - first + 1;
}


int main() {
    vector<int> nums = { 1,2,2,2,3 };
    int target = 2;

    cout << count_occurrences(nums, target);

    return 0;
}