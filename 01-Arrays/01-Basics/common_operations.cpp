// Common array / vector operations

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = { 5, 1, 4, 2, 3 };

    sort(v.begin(), v.end());          // sort
    reverse(v.begin(), v.end());       // reverse
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());

    bool found = binary_search(v.begin(), v.end(), 3);

    return 0;
}
