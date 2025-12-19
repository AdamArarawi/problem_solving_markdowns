#include <bits/stdc++.h>
using namespace std;
void SumofRightSide(vector<int> nums) {
    int n = nums.size();

    vector<int> suf(n);

    suf[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = nums[i + 1] + suf[i + 1];
    }

    for (int i : suf) {
        cout << i << " ";
    }
}

void MiddleIndexWithSuf(vector<int> nums) {
    int n = nums.size();

    vector<int> suf(n);

    suf[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = nums[i + 1] + suf[i + 1];
    }
    int left = 0;
    for (int i = 0; i < n; i++) {
        int right = suf[i];

        if (left == right) {
            cout << i;
            return;
        }
        left += nums[i];
    }
    cout << -1;
}

int main() {
    vector<int> nums = { 2, 4, 1, 3, 5 };
    int n = nums.size();

    vector<int> suf(n);

    suf[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + nums[i];
    }
    cout << '\n';
    for (int i : suf) {
        cout << i << " ";
    }
    cout << '\n';
    SumofRightSide(nums);
    cout << '\n';
    MiddleIndexWithSuf(nums);

    return 0;
}

