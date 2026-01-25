import sys
input = sys.stdin.readline
print = sys.stdout.write

def upper_bound(nums, target):
    l = 0
    r = len(nums) - 1
    ans = len(nums)

    while l <= r:
        mid = (l + r) // 2
        if nums[mid] > target:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1

    return ans

nums = input().split() 
target = input().strip()    

idx = upper_bound(nums,target)

if idx == len(nums):
    print(nums[0])
else:
    print(nums[idx])