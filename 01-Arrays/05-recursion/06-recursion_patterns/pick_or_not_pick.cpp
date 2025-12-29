#include <bits/stdc++.h>
using namespace std;

void pick_not_pick(int i, vector<int> &nums, vector<int> &cur)
{
    if (i == nums.size())
    {
        for (int j : cur)
            cout << j << " ";
        cout << '\n';
        return;
    }
    pick_not_pick(i + 1, nums, cur);
    cur.push_back(nums[i]);
    pick_not_pick(i + 1, nums, cur);
    cur.pop_back();
}

void pick_not_pick_base(vector<int> &nums)
{
    vector<int> cur;
    pick_not_pick(0, nums, cur);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    pick_not_pick_base(nums);
    return 0;
}