#include <bits/stdc++.h>
using namespace std;

int sumArray(vector<int> &nums, int i, int sum)
{
    if (i == nums.size())
        return sum;
    sum += nums[i];
    return sumArray(nums, i + 1, sum);
}