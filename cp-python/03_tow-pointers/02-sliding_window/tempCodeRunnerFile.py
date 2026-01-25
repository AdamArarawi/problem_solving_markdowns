while currSum >= k and l <i:
        minLen = min(i - l, minLen)
        currSum -= nums[l]
        l += 1
    