import sys
input = sys.stdin.readline
output = sys.stdout.write

s = "abcabcbb"
chars = set()
maxLen = 0
l = 0

for i,val in enumerate(s):
    while val in chars:
        chars.remove(s[l])
        l+=1
    chars.add(val)
    maxLen = max(maxLen, i - l + 1)


output(str(maxLen))
