nums = [10, 9, 2, 5, 3, 7, 101, 18]
n = len(nums)

dp = [1] * n

for i in range(n):
    for j in range(i):
        if nums[j] > nums[i]:
            dp[i] = max(dp[i], dp[j] + 1)


print(max(dp))