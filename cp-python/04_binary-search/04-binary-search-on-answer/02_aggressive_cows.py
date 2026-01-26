import sys
input = sys.stdin.readline
print = sys.stdout.write

def check(stalls, c, space):
    lastcow = stalls[0]
    numCows = 1

    for val in stalls[1:]:
        if val - lastcow >= space:
            lastcow = val
            numCows += 1

    return numCows >= c

def bin_on_answer(stalls, c):
    l = 1
    r = max(stalls) - min(stalls)
    ans = r

    while l <= r:
        mid = (l + r) // 2
        if (check(stalls, c, mid)):
            ans = mid
            l = mid + 1

        else:
            r = mid - 1
    return ans


stalls = list(map(int, input().split()))
c = int(input())
stalls.sort()
print(str(bin_on_answer(stalls, c)))