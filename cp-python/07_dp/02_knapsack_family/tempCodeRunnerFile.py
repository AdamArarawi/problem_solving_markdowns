coins = [1, 2, 5]
n = len(coins)
target = 11
INF = int(1e9)
dp = [INF] * (target + 1)

dp[0] = 0
for i in range(1, n + 1):
    for w in range(1, target + 1):
        dp[w] = min(dp[w], dp[w - coins[i-1]] + i)

print(dp[target])