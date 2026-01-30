n = 3
m = 3
grid = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]

dp = [[0] * m for _ in range(n)]


for j in range(m):
    if grid[0][j] == 1: break 
    dp[0][j] = 1

for i in range(n):
    if grid[i][0] == 1: break
    dp[i][0] = 1


for i in range(1,n):
    for j in range(1,m):
        if grid[i][j] == 1:
            dp[i][j] = 0
            continue
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

print(dp[n-1][m-1])
