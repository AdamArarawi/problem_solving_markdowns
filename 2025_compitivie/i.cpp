#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n;
    int arr[n];
    int result = -1;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        if (freq[arr[i]] > n / 2)
        {
            result = arr[i];
        }
    }

    cout << result;
    return 0;
}