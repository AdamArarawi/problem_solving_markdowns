import sys
input = sys.stdin.readline
output = sys.stdout.write

n = int(input())
seen = set()
result = True

while n != 1:
    curr_sum = 0
    temp = n
    while temp > 0:
        digit = temp % 10
        curr_sum += digit * digit
        temp //= 10

    if curr_sum in seen:
        result = False
        break

    seen.add(curr_sum)
    n = curr_sum

output(str(result))
