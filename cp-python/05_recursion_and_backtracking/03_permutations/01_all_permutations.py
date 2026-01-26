import sys
input = sys.stdin.readline
print = sys.stdout.write 
nums = list(map(int, input().split())) 
result = [] 
def subsets(curr:list = [],se: set = set()): 
    if len(curr) == len(nums): 
        result.append(curr[:]) 
        return 
    for i in nums: 
        if i not in se: 
            curr.append(i) 
            se.add(i)
            subsets(curr,se) 
            curr.pop() 
            se.remove(i)


subsets() 
print(str(result))