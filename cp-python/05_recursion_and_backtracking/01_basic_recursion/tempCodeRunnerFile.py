import sys
input = sys.stdin.readline
print = sys.stdout.write

def digit(n):
    if n <=1:
        return n
    return n%10 + digit(n//10)


n = int(input())
print(str(digit(n)))