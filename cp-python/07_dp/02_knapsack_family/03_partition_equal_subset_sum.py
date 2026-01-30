nums = [1, 5, 11, 5]
n = len(nums)
total = sum(nums)

target = total // 2


# dp = [[False] * (target + 1) for _ in range(n+1)]

# for i in range(n+1):
#     dp[i][0] = True

# for i in range(1,n+1):
#     for w in range(1, target + 1):
#         if nums[i - 1] <= w:
#             dp[i][w] = dp[i-1][w] or dp[i-1][w - nums[i-1]]
#         else:
#             dp[i][w] = dp[i-1][w]

dp = [False] * (target + 1)
dp[0] = True

for i in range(1,n+1):
    for w in range(target, nums[i-1]-1, -1):
        dp[w] = dp[w] or dp[w - nums[i-1]]


print(dp[target])