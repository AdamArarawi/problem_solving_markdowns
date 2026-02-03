from typing import List

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
    
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        curr = 0

        for num in nums:
            if count == 0:
                curr = num
            
            if num == curr:
                count += 1
            else:
                count -= 1
        return curr
    
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = [[1] for _ in range(numRows)]
        
        for i in range(1,numRows):
            for j in range(1,i):
                pascal[i].append(pascal[i-1][j-1] + pascal[i-1][j])
            pascal[i].append(1)
        return pascal
    
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid - 1

        return -1
    
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + arr[i]
        
        total = 0
        
        for length in range(1, n+1, 2):
            for start in range(n - length + 1):
                end = start + length - 1
                sum_subarray = prefix[end+1] - prefix[start]
                total += sum_subarray
        
        return total

    def longestPalindrome(s: str) -> str:
        n = len(s)
        if n == 0:
            return ""
        
        dp = [[False] * n for _ in range(n)]
        
        start_max = 0
        length_max = 1
        
        for i in range(n):
            dp[i][i] = True
        
        for length in range(2, n+1):  
            for i in range(n - length + 1):
                j = i + length - 1 
                
                if s[i] == s[j]:
                    if length == 2:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1] 
                else:
                    dp[i][j] = False
                
                if dp[i][j] and length > length_max:
                    start_max = i
                    length_max = length
        
        return s[start_max:start_max + length_max]

