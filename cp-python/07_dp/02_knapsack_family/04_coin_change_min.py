coins = [1, 2, 5]
n = len(coins)
target = 11
INF = int(1e9)
dp = [INF] * (target + 1)

dp[0] = 0
for i in range(n):
    for w in range(1, target + 1):
        if w >= coins[i]:
            dp[w] = min(dp[w], dp[w - coins[i]] + 1)

# for i in range(n):
#     for w in range(1, target + 1):
#         if w >= coins[i]:
#             dp[i][w] = min(dp[i-1][w], dp[i][w - coins[i]] + 1)
#         else:
#             dp[i][w] = dp[i-1][w]

print(dp[target])
