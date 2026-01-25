import sys
input = sys.stdin.readline
print = sys.stdout.write

def bin_search(nums, target):
    l = 0
    r = len(nums) - 1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            return mid
        if  nums[l] <= nums[mid]:
            if nums[l] <= target < nums[mid]:
                r = mid - 1
            else: 
                l = mid + 1
        else:
            if nums[mid] < target <= nums[r]:
                l = mid + 1
            else: 
                r = mid - 1

    return -1

if __name__ == "__main__":
    try:
        nums = list(map(int, sys.stdin.readline().split()))
        target = int(sys.stdin.readline())
        
        result = bin_search(nums, target)
        sys.stdout.write(str(result) + '\n')
    except EOFError:
        pass