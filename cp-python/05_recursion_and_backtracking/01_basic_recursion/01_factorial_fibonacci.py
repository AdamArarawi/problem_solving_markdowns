import sys
input = sys.stdin.readline
print = sys.stdout.write

def fib(n):
    if n <= 1:
        return n
    
    return fib(n - 1) + fib(n - 2)

memo = {}
def fib_memo(n):
    if n <= 1:
        return n
    if n in memo:
        return memo[n]
    
    memo[n] = fib(n - 1) + fib(n - 2)
    return memo[n]

n = int(input())

print(str(fib(n)))