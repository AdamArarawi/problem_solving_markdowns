#include <bits/stdc++.h>
using namespace std;

bool twoPointersSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << "Pair found: " << arr[left] << ", " << arr[right] << "\n";
            return true;
        }
        else if (sum < target) {
            left++;   // sum صغير → نحتاج أكبر → نزيّد left
        }
        else {
            right--;  // sum كبير → نحتاج أصغر → نقلل right
        }
    }

    return false;
}

int main() {
    vector<int> arr = { 1, 3, 4, 6, 8 };
    int target = 10;
    twoPointersSum(arr, target);
}
