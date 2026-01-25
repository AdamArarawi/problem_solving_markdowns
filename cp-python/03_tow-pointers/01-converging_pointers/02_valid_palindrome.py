import sys
input = sys.stdin.readline
output = sys.stdout.write

s = input().strip()

l = 0
r = len(s) - 1

result = True
while l < r:
    if s[l] != s[r]:
        result = False
        break
    
    l += 1
    r -= 1

output(str(result))