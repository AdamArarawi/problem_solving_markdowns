text1 = "abcde"
text2 = "ace"

n = len(text1)
m = len(text2)

dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1,n + 1):
    for j in range(1,m + 1):
        if text1[i-1] == text2[j - 1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[n][m])


x, y = n, m
common = ""

while x > 0 and y > 0:
    if text1[x - 1] == text2[y - 1]:
        common += text1[x - 1]
        x -= 1
        y -= 1
    elif dp[x - 1][y] >= dp[x][y - 1]:
        x -= 1
    else:
        y -= 1

print(common[::-1])
