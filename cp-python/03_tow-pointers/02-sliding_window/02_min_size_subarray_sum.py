import sys
input = sys.stdin.readline
output = sys.stdout.write

nums = [2, 3, 1, 2, 4, 3]
k = 7

minLen = float("inf")
currSum = 0
l = 0

for i, val in enumerate(nums):
    currSum += val  # نضيف العنصر الحالي دائمًا
    
    while currSum >= k:
        minLen = min(minLen, i - l + 1)
        currSum -= nums[l]
        l += 1

if minLen == float("inf"):
    minLen = 0

output(str(minLen))  # Output: 2
