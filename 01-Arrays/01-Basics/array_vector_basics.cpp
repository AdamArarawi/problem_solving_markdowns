// Arrays & Vectors Basics
// - Declaration
// - Traversal
// - Pass to function
// - Common pitfalls

#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };

    vector<int> v = { 1, 2, 3, 4, 5 };
    v.push_back(6);
    v.pop_back();

    printVector(v);

    return 0;
}
