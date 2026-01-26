import sys
import math
input = sys.stdin.readline
print = sys.stdout.write

def check(piles, h, k):
    hours = 0
    for i in piles:
        hours += math.ceil(i / k)
    return hours <= h

def bin_on_answer(piles, h):
    l = 1
    r = max(piles)
    ans = r
    
    while l <= r:
        mid = (l + r) // 2
        if check(piles, h, mid):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans

piles = list(map(int, input().split()))
h = int(input())

print(str(bin_on_answer(piles, h)))
