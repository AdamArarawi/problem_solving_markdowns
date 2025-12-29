#include <bits/stdc++.h>
using namespace std;

int sumOfArray(vector<int> &nums, int i)
{
    if (i == nums.size())
        return 0;
    return nums[i] + sumOfArray(nums, i + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sumOfArray(nums, 0);
    return 0;
}