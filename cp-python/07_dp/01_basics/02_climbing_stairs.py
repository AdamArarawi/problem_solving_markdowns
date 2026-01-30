n = int(input())

if n <= 1:
    print(1)
else:
    prev_prev = 1 
    prev = 1
    
    for i in range(2, n + 1):
        curr = prev + prev_prev
        prev_prev = prev
        prev = curr
    print(prev)