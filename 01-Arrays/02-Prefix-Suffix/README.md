# Prefix & Suffix Guide

This is a concise guide for understanding **Prefix Sum** and **Suffix Sum** patterns in Problem Solving.  
Use this as a reference before starting any problem.

---

## 1. Prefix Sum (Cumulative from Left)

### Definition

-   `pref[i] = sum of elements from index 0 to i`
-   Useful for quickly computing **subarray sums**.

### Construction (C++)

```cpp
vector<int> pref(n);
pref[0] = arr[0];
for(int i = 1; i < n; i++)
    pref[i] = pref[i-1] + arr[i];
```

### Common Uses

1. **Range sum queries**: sum of subarray `[l, r]` in O(1)

    ```cpp
    int rangeSum = (l == 0) ? pref[r] : pref[r] - pref[l-1];
    ```

2. **Longest subarray with sum = k** (using HashMap)
3. **Optimizations**:

    - Combine with **Binary Search** for sum constraints
    - Combine with **Difference Array** for range updates
    - Use modulo for divisibility/remainder problems

### Notes

-   Sometimes store **first occurrence only** in HashMap for longest subarray problems.
-   Initialize `freq[0] = 1` if using HashMap to handle subarrays starting at index 0.

---

## 2. Suffix Sum (Cumulative from Right)

### Definition

-   `suf[i] = sum of elements from index i+1 to n-1` (right side)
-   Useful for **right-side sums** or when combining left + right info.

### Construction (C++)

```cpp
vector<int> suf(n);
suf[n-1] = 0;  // sum of elements to the right of last element
for(int i = n-2; i >= 0; i--)
    suf[i] = arr[i+1] + suf[i+1];
```

### Common Uses

1. **Middle index problems**: find index where left sum = right sum
2. **Product of array except self** (precompute right products)
3. **Max on right / min on right** problems
4. Combine with **Two Pointers** for hybrid approaches

### Notes

-   Sometimes `suf[n-1] = arr[n-1]` if you want **sum from i to end**
-   Conceptually, Suffix = "what's to the right of me"

---

## 3. Mental Checklist Before Using Prefix/Suffix

-   Do you need **range sums / left sums / right sums**? → Prefix/Suffix
-   Do you need **longest / count / product**? → Combine with HashMap or Suffix
-   Can the array have negative numbers? → HashMap is safer for sum = k
-   Are you optimizing subarray queries? → Prefix + Binary Search or Sliding Window

---

## 4. Quick Patterns / Combos

| Pattern                | When to Use                         | Extra Tips                              |
| ---------------------- | ----------------------------------- | --------------------------------------- |
| Prefix Only            | Subarray sum / range queries        | O(1) query after O(n) prep              |
| Prefix + HashMap       | Count / Longest subarray with sum k | Store first occurrence for longest      |
| Prefix + Binary Search | Min/Max sum constraints             | Array may need sorting                  |
| Suffix Only            | Right-side sum / product / max/min  | Good for “everything after i”           |
| Prefix + Suffix        | Middle index, product except self   | Combine left and right info efficiently |

---

## 5. Key Takeaways

-   Prefix = sum from **start to current index**
-   Suffix = sum from **current index to end**
-   Always ask: _do I need left info, right info, or both?_
-   Combine with **HashMap, Sliding Window, or Two Pointers** for advanced problems
-   Practicing small patterns is better than memorizing code

---

Keep this as your mental cheat sheet for **Prefix & Suffix patterns**!
