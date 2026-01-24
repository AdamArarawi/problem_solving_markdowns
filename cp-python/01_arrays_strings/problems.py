import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

# 1) max
print(max(arr))

total = sum(arr)
cnt = 0
for x in arr:
    if x * n > total:
        cnt += 1
print(cnt)

arr.reverse()
print(arr)

b = arr[:]  
l, r = 0, n-1
ok = True
while l < r:
    if b[l] != b[r]:
        ok = False
        break
    l += 1; r -= 1
print(ok)

k = 2
k %= n
arr[:] = arr[-k:] + arr[:-k]
print(arr)
