#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int curr = 0;
    int maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            maxSum = max(maxSum, curr);
            curr = 0;
        }
        else
        {
            curr += arr[i];
        }
    }

    cout << max(curr, maxSum);

    return 0;
}