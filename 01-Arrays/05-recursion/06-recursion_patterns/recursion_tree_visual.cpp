#include <bits/stdc++.h>
using namespace std;
void sub_arrays(int i, vector<int> &nums, vector<int> &cur)
{
    if (i == nums.size())
    {
        cout << "{";
        for (int j = 0; j < cur.size(); j++)
        {
            cout << cur[j];
            if (j + 1 < cur.size())
                cout << ", ";
        }
        cout << "}";
        cout << '\n';
        return;
    }

    // skip
    sub_arrays(i + 1, nums, cur);

    // take
    cur.push_back(nums[i]);
    sub_arrays(i + 1, nums, cur);
    cur.pop_back();
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> cur;
    sub_arrays(0, nums, cur);
    cur.clear();
    return 0;
}