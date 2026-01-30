nums = [3, 34, 4, 12, 5, 2]
n = len(nums)
target = 9

dp = [False] * (target + 1 )
dp[0] = True

for i in range(1,n+1):
    for w in range(target, nums[i-1]-1, -1):
        dp[w] = dp[w] or dp[w-nums[i-1]]

print(dp[target])
# for i in range(1,n+1):
#     for w in range(1,target + 1):
#         if nums[i-1] <= w:

#             dp[i][w] = dp[i-1][w] or dp[i-1][w-nums[i-1]]
#         else:
#             dp[i][w] = dp[i-1][w]

# for i in dp:
#     print(i)
