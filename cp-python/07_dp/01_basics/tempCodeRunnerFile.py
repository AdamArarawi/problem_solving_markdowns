n = int(input())


prev_prev = 1
prev = 1

for i in range(n):
    curr = prev + prev_prev
    prev_prev = prev
    prev = curr
print(prev_prev + prev)
