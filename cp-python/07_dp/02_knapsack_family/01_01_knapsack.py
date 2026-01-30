n = 3
W = 50
weights = [10, 20, 30]
values = [60, 100, 120]

# dp = [[0] * (W+1) for _ in range(n+1)]

# for i in range(1,n+1):
#     for w in range(1,W + 1):
#         if weights[i-1] <= w:
#             dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i - 1]] + values[i-1])
#         else:
#             dp[i][w] = dp[i-1][w]

# print(dp[n][W])

dp = [0] * (W + 1)

for i in range(n):
    for w in range(W, weights[i] - 1, -1):
        dp[w] = max(dp[w], dp[w - weights[i]] + values[i])

print(dp[W])
