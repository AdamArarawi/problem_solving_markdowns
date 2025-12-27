#include <bits/stdc++.h>
using namespace std;


int binary_search_on_answer(int x) {
    int l = 0, r = x;
    int result = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid * mid <= x) {
            result = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return result;

}


int main() {
    int x = 10;

    cout << binary_search_on_answer(x);

    return 0;
}