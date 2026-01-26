import sys
input = sys.stdin.readline
print = sys.stdout.write

def reverse(s: str):
    if (len(s) == 0):
        return ""
    last = s[-1]
    new_s = s[:-1]
    return last + reverse(new_s)

s = input().strip()

print(reverse(s))