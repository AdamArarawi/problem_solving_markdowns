import sys
input = sys.stdin.readline
print = sys.stdout.write

nums = list(map(int, input().split()))

result = []

def subsets(nums, i, curr):
    result.append(curr[:])
    
    if i == len(nums):
        return
    
    curr.append(nums[i])
    subsets(nums, i+1, curr)
    
    curr.pop()
    subsets(nums, i+1, curr)

subsets(nums, 0, [])

print(str(result))
