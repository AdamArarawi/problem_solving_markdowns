#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = { 1, 2, 4, 6, 8, 9 };
    int target = 10;

    int l = 0, r = nums.size() - 1;
    pair<int, int> result = { -1,-1 };
    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum == target) {
            result = { l,r };
            break;
        }
        else if (sum, target) l++;
        else r--;
    }

    cout << result.first << " " << result.second;

    return 0;
}

