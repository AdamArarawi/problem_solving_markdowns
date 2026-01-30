class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        else:
            prev_prev = 1 
            prev = 1
            
            for _ in range(2, n + 1):
                curr = prev + prev_prev
                prev_prev = prev
                prev = curr
            return prev
        
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        fi = [0] * n
        fi[0] = 1
        fi[1] = 1
        for i in range(2,n):
            fi[i] = fi[i - 1] + fi[i-2]
        
        return fi[n - 1]
    
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = 10e4
        dp = [INF] * (amount + 1)

        dp[0] = 0

        for i in range(len(coins)):
            for w in range(amount + 1):
                if coins[i] >= w:
                    dp[w] = min(dp[w], dp[w - coins[i]] + 1)

        return dp[amount]
    
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)

        dp[0] = 1

        for coin in coins:
            for i in range(coin,amount + 1):
                    dp[i] += dp[i - coin] 
        return dp[amount]

    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        target = total // 2
        if total % 2 != 0:
            return False
        dp = [False] * (target + 1)
        

        dp[0] = True

        for num in nums:
            for i in range(target, num-1, -1):
                dp[i] = dp[i] or dp[i - num]
        
        return dp[target]

    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0]*(n+1) for _ in range(m+1)]  

        for s in strs:          
            zeros = s.count('0')
            ones = s.count('1')
            
            for i in range(m, zeros-1, -1): 
                for j in range(n, ones-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1)

    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        target = total // k
        if total % 2 != 0:
            return False
        dp = [False] * (target + 1)
        

        dp[0] = True

        for num in nums:
            for i in range(target, num-1, -1):
                dp[i] = dp[i] or dp[i - num]
        
        return dp[target]
        
        




