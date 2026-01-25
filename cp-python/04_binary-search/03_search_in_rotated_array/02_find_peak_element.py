import sys
input = sys.stdin.readline
print = sys.stdout.write

def minimum(nums):
    l = 0
    r = len(nums) - 1
    while l < r:
        mid = (l + r) // 2
        if nums[mid] > nums[r]:
            l = mid + 1
        else:
            r = mid

    return nums[l]


def maximum(nums):
    l = 0
    r = len(nums) - 1
    while l < r:
        mid = (l + r) // 2
        if nums[mid] > nums[r]:
            l = mid 
        else:
            r = mid - 1 

    return nums[l]

def find_peak(nums):
    l = 0
    r = len(nums) - 1
    
    while l < r:
        mid = (l + r) // 2
        if nums[mid] < nums[mid + 1]:
            l = mid + 1
        else:
            r = mid
            
    return l


if __name__ == "__main__":
    try:
        nums = list(map(int, sys.stdin.readline().split()))        
        result = maximum(nums)
        sys.stdout.write(str(result) + '\n')
    except EOFError:
        pass