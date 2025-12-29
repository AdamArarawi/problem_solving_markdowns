#include <bits/stdc++.h>
using namespace std;
void generate_combinations(int i, vector<int> &nums, vector<int> &cur, int k)
{
    // base condition
    if (cur.size() == k)
    {
        for (int x : cur)
            cout << x << " ";
        cout << '\n';
        return;
    }
    if (i == nums.size())
        return;

    // take
    cur.push_back(nums[i]);
    generate_combinations(i + 1, nums, cur, k);
    cur.pop_back();

    // skip
    generate_combinations(i + 1, nums, cur, k);
}

void generate_combinations_with_n(int i, int n, vector<int> &cur, int k)
{
    // base condition
    if (cur.size() == k)
    {
        for (int x : cur)
            cout << x << " ";
        cout << '\n';
        return;
    }
    if (i > n)
        return;

    // take
    cur.push_back(i);
    generate_combinations_with_n(i + 1, n, cur, k);
    cur.pop_back();

    // skip
    generate_combinations_with_n(i + 1, n, cur, k);
}
void pruning(int i, vector<int> &nums, vector<int> &cur, int k, int target, int currentSum)
{
    // base condition
    if (cur.size() == k)
    {
        if (currentSum <= target)
        {
            for (int x : cur)
                cout << x << " ";
            cout << '\n';
        }
        return;
    }
    if (i >= nums.size())
        return;
    if (currentSum > target)
        return;

    // take
    cur.push_back(nums[i]);
    pruning(i + 1, nums, cur, k, target, currentSum + nums[i]);
    cur.pop_back();

    // skip
    pruning(i + 1, nums, cur, k, target, currentSum);
}
void generate_combinations_with_sum_of_target(int start, vector<int> &nums, vector<int> &cur, int target)
{

    if (target == 0)
    {
        for (int x : cur)
            cout << x << " ";
        cout << '\n';
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {

        // ❗ منع التكرار
        if (i > start && nums[i] == nums[i - 1])
            continue;

        // pruning
        if (nums[i] > target)
            break;

        cur.push_back(nums[i]);
        generate_combinations_with_sum_of_target(i + 1, nums, cur, target - nums[i]);
        cur.pop_back();
    }
}
int main()
{
    vector<int> nums = {1, 1, 2, 5};
    vector<int> cur;
    unordered_map<int, int> memo;
    // generate_combinations(0, nums, cur, 2); cur.clear();
    // generate_combinations_with_n(1, 4, cur, 2);
    // pruning(0, nums, cur, 2, 3, 0);
    generate_combinations_with_sum_of_target(0, nums, cur, 3);
}
