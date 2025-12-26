#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> nums = { 1,2,3,4,2,1,5 };
    int k = 3;

    int result = 0;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    result = sum;

    for (int i = k; i < nums.size();i++) {
        sum -= nums[i - k];
        sum += nums[i];
        result = max(result, sum);
    }

}
