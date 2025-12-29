#include <bits/stdc++.h>
using namespace std;

bool tail_isSorted(vector<int> &nums, int i)
{
    if (i == nums.size() - 1)
        return true;
    if (nums[i] > nums[i + 1])
        return false;
    return tail_isSorted(nums, i + 1);
}

bool isSorted(vector<int> &nums) { return tail_isSorted(nums, 0); }

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << isSorted(nums);
    return 0;
}