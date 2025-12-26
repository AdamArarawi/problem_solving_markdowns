#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> heights = { 1,8,6,2,5,4,8,3,7 };


    int l = 0, r = heights.size() - 1, maxSize = 0;


    while (l < r)
    {
        int w = r - l;
        int h = min(heights[l], heights[r]);
        int size = w * h;
        maxSize = max(size, maxSize);

        if (heights[l] < heights[r]) l++;
        else r--;
    }

    cout << maxSize;


    return 0;
}

