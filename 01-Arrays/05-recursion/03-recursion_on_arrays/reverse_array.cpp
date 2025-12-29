#include <bits/stdc++.h>
using namespace std;

void tail_reverse_array(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    swap(nums[l], nums[r]);
    return tail_reverse_array(nums, l + 1, r - 1);
}

void reverse_array(vector<int> &nums) { return tail_reverse_array(nums, 0, nums.size() - 1); }

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    reverse_array(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}