import sys
input = sys.stdin.readline
output = sys.stdout.write

nums = [2, 1, 5, 1, 3, 2]
k = 3

maxSum = 0
for i in range(0, k):
    maxSum += nums[i]

currSum= maxSum
for i in range(k, len(nums)):
    currSum = currSum -nums[i-k] + nums[i]
    maxSum = max(maxSum, currSum)

output(str(maxSum))