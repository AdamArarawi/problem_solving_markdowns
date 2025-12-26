#include <bits/stdc++.h>
using namespace std;

int trapRainWaterPrefix() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int n = height.size();

    vector<int> leftMax(n, 0);

    int pref = height[0];
    for (int i = 0; i < n; i++) {
        pref = max(height[i], pref);
        leftMax[i] = pref;
    }

    vector<int> rightMax(n, 0);

    int suff = height[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        suff = max(height[i], suff);
        rightMax[i] = suff;
    }

    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        int water = min(leftMax[i], rightMax[i]) - height[i];
        if (water > 0) {
            totalWater += water;
        }
    }
    return totalWater;
}


int main() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };


    int l = 0, r = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            leftMax = max(leftMax, height[l]);
            total += leftMax - height[l];
            l++;
        }
        else {
            rightMax = max(rightMax, height[r]);
            total += rightMax - height[r];
            r--;
        }
    }

    cout << total;


}
