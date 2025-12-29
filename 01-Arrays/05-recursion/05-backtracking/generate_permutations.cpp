#include <bits/stdc++.h>
using namespace std;
void generate_permutations(vector<int> &nums, vector<bool> &used, vector<int> &curr)
{
    // base condition
    if (nums.size() == curr.size())
    {
        for (int i : curr)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            curr.push_back(nums[i]);
            generate_permutations(nums, used, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<bool> used(nums.size());
    vector<int> curr;
    generate_permutations(nums, used, curr);
    return 0;
}