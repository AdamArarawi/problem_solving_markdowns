"""
    Count Subsets With Given Difference
"""

nums = [1,1,2,3]
n = len(nums)
D = 1

total = sum (nums)

dp = [[0] * (total+1) for _ in range(n + 1)]

for i in range(n + 1):
    dp[i][0] = 1

for i in range(1,n + 1):
    for j in range(1, total + 1):
        dp[i][j] = dp[i-1][j] 
        if j >= nums[i-1]:
            dp[i][j] += dp[i-1][j-nums[i-1]] 

target = (D + total) // 2
# if (D + total) % 2 != 0 or target > total:
#     print(0)
# else:
#     print(dp[n][target])

"""
    Count Ways to Reach a Score
"""

nums = [3,5,10]
n = len(nums)
target = 20

dp = [[0] * (target + 1) for _ in range(n + 1)]

for i in range(n + 1):
    dp[i][0] = 1

for i in range(1,n+1):
    for j in  range(1, target + 1):
        dp[i][j] = dp[i-1][j]
        if j >= nums[i - 1]:
            dp[i][j] +=  dp[i][j - nums[i-1]]
        

# print(dp[n][target])


"""
    Count Subarrays With Sum = K
"""
nums = [1,2,3,4,5]
k = 7

mp = {0: 1}
pref = 0
count = 0
for num in nums:
    pref += num

    if (pref- k) in mp:
        count += mp[pref - k]

    if pref not in mp:
        mp[pref] = 1
    else:
        mp[pref] += 1

# print(count)


"""
    Minimum Number of Perfect Squares
"""
import math
n = 12
m = int(math.sqrt(n))

dp = [[n] * (n + 1) for _ in range(m + 1)]
sqrts = [0] * (m)
sqrts[0] = 1
for i in range(1, m+1):
    if i * i <= n:
        sqrts[i - 1] = i * i

for i in range(m + 1):
    dp[i][0] = 0

for i in range(1,m+1):
    for j in range(1, n + 1):
        if j >= sqrts[i - 1]:
            dp[i][j] = min(dp[i-1][j], dp[i][j - sqrts[i - 1]] + 1)
        else:
            dp[i][j] = dp[i-1][j]

# print(dp[m][n])

"""
    Rod Cutting
"""

prices = [1,5,8,9,10,17,17,20]
n = len(prices)
lenght = 8

dp = [[0] * (lenght + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, lenght + 1):
        if j >= i:
            dp[i][j] = max(dp[i-1][j], dp[i][j - i] + prices[i - 1])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[lenght][n])