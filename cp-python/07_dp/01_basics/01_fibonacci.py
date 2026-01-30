import sys

def solve():
    line = sys.stdin.readline()
    if not line: return
    n = int(line)
    MOD = 10**9 + 7

    if n == 0:
        sys.stdout.write("0\n")
        return
    if n == 1:
        sys.stdout.write("0 1\n")
        return

    fib = [0] * (n + 1)
    fib[0] = 0
    fib[1] = 1
    
    for i in range(2, n + 1):
        fib[i] = (fib[i-1] + fib[i-2]) % MOD

    sys.stdout.write(" ".join(map(str, fib)) + "\n")

solve()