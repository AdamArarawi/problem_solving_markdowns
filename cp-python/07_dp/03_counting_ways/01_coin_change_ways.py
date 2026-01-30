coins = [1, 2, 5]
n = len(coins)
target = 11
INF = int(1e9)
dp = [0] * (target + 1)

dp[0] = 1
for i in range(n):
    for w in range(coins[i], target + 1):
            dp[w] += dp[w-coins[i]]

print(dp[target])
