#include <bits/stdc++.h>
using namespace std;

int sum(int l, int r, vector<int> &pref)
{
    if (l == 0)
        return pref[r];
    return pref[r] - pref[l - 1];
}

int main()
{
    vector<int> a = {2, 4, 1, 3, 5};
    int n = a.size();

    vector<int> pref(n);

    pref[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int x : pref)
    {
        cout << x << " ";
    }
}

// Returns the maximum sum of any subarray with length exactly k
int maxSubarraySumOfLengthK(const vector<int> &a, int k)
{
    int n = a.size();

    // Build prefix sum array
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    int maxSum = INT_MIN;

    // Try all subarrays with length k
    for (int i = k - 1; i < n; i++)
    {
        int currSum;

        // If subarray starts from index 0
        if (i == k - 1)
            currSum = pref[i];
        else
            currSum = pref[i] - pref[i - k];

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// Returns true if there exists at least one subarray with sum = k
bool existsSubarrayWithSumK(const vector<int> &a, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1; // Prefix sum = 0 exists once before starting

    int pref = 0;

    for (int i = 0; i < a.size(); i++)
    {
        pref += a[i];

        // Check if there is a previous prefix such that:
        // pref - previous = k
        if (freq[pref - k] > 0)
            return true;

        freq[pref]++;
    }

    return false;
}

// Returns the number of subarrays with sum = k
int countSubarraysWithSumK(const vector<int> &a, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1; // Important for subarrays starting at index 0

    int pref = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++)
    {
        pref += a[i];

        // Number of valid subarrays ending here
        count += freq[pref - k];

        freq[pref]++;
    }

    return count;
}

// Returns the length of the longest subarray with sum = k
int longestSubarrayWithSumK(const vector<int> &a, int k)
{
    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1; // Prefix sum 0 occurs before array starts

    int pref = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++)
    {
        pref += a[i];

        // If there exists a prefix such that:
        // pref - previous = k
        if (firstIndex.count(pref - k))
        {
            int len = i - firstIndex[pref - k];
            maxLen = max(maxLen, len);
        }

        // Store only the first occurrence to maximize length
        if (!firstIndex.count(pref))
        {
            firstIndex[pref] = i;
        }
    }

    return maxLen;
}
