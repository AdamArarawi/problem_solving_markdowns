import sys
input = sys.stdin.readline
output = sys.stdout.write

a = list(map(int, input().split()))
k = int(input())

l = 0
r = len(a) - 1

result = []
while l < r:
    sumOfLAndR = a[l] + a[r]
    if sumOfLAndR == k:
        result = [a[l], a[r]]
        break
    
    elif sumOfLAndR < k:
        l += 1
    else:
        r -= 1

output(str(result))