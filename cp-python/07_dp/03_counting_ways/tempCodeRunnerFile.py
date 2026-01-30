import math
n = 12
m = int(math.sqrt(n))

dp = [[n] * (n + 1) for _ in range(m + 1)]
sqrts = [0] * (m)
sqrts[0] = 1
for i in range(1, m+1):
    if i * i <= n:
        sqrts[i - 1] = i

for i in range(m + 1):
    dp[i][0] = 0

for i in range(1,m+1):
    for j in range(1, n + 1):
        if j >= sqrts[i - 1]:
            dp[i][j] = min(dp[i-1][j], dp[i][j - sqrts[i - 1]] + 1)
        else:
            dp[i][j] = dp[i-1][j]

print(dp[m][n])