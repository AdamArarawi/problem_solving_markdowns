#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& weights, int k, int mid) {
    int days = 1;
    int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i];
        if (sum > mid) {
            days += 1;
            sum = weights[i];
        }
    }
    return days <= k;
}

int binary_search_on_answer(vector<int>& weights, int k, int minW, int maxW) {
    int l = minW, r = maxW;
    int result = maxW;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (canSplit(weights, k, mid)) {
            result = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return result;

}


int main() {
    vector<int> weights = { 3,2,2,4,1,4 };
    int k = 3;
    int minW = 0, maxW = 0;
    for (int i = 0; i < weights.size();i++) {
        maxW += weights[i];
        minW = max(minW, weights[i]);
    }

    cout << binary_search_on_answer(weights, k, minW, maxW);

    return 0;
}