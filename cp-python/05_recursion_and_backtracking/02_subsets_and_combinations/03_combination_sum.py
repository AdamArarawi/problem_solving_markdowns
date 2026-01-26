import sys
input = sys.stdin.readline
print = sys.stdout.write

nums = list(map(int, input().split()))
target = int(input())
result = []

def subsets(start, curr, total):
    if total == target:
        result.append(curr[:])
        return
    elif total > target:
        return
    
    for i in range(start, len(nums)):
        curr.append(nums[i])
        subsets(i, curr, total + nums[i])
        curr.pop()


subsets(0,[],0)

print(str(result))
