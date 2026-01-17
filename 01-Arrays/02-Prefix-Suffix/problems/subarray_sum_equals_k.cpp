#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> m;
    m[0] = 1;
    int count = 0;
    int pref = 0;
    for (int i = 0; i < n; i++)
    {
        pref += nums[i];

        count += m[pref - k];

        m[pref]++;
    }

    cout << count;
    return 0;
}

int main2()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> m;
    m[0] = 1;
    long long pref = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        pref += nums[i];
        int rem = ((pref % k) + k) % k;
        count += m[rem];
        m[rem]++;
    }

    cout << count;
    return 0;
}
