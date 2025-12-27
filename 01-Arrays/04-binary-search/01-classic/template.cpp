#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    int target = 2;
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return 0;
}
