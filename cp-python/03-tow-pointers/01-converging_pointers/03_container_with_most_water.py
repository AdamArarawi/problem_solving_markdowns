import sys
input = sys.stdin.readline
output = sys.stdout.write

height = [1,8,6,2,5,4,8,3,7]

l = 0
r = len(height) - 1
maxSize = 0

while l < r:
    w = r - l
    h = min(height[r], height[l])
    size = w * h
    maxSize = max(maxSize, size)

    if (height[r] >  height[l]):
        l+= 1
    else:
        r -= 1

output(str(maxSize))

