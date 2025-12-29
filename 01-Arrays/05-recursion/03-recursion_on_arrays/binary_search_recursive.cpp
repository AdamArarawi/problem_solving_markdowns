#include <bits/stdc++.h>
using namespace std;

int tail_binary_search(vector<int> &nums, int target, int l, int r)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return tail_binary_search(nums, target, l + 1, r);
    else
        return tail_binary_search(nums, target, l, r - 1);
}

int binary_search(vector<int> &nums, int target) { return tail_binary_search(nums, target, 0, nums.size() - 1); }

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << binary_search(nums, 6);
    return 0;
}