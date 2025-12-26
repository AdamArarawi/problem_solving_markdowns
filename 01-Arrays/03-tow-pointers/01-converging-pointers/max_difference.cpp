#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    int left = 0;
    int best = 0;

    for (int right = 1; right < prices.size(); right++) {
        if (prices[right] < prices[left]) {
            left = right;
        }
        else {
            best = max(best, prices[right] - prices[left]);
        }
    }

    return 0;
}