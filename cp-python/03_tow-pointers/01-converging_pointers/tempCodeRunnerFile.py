import sys
input = sys.stdin.readline
output = sys.stdout.write

a = [1, 2, 3, 4, 5]
k = 10

l = 0
r = len(a) - 1

maxSum = 0
while l < r:
    curr_sum = a[l] + a[r]
    if (abs(k - maxSum) > abs(k -curr_sum)):
        maxSum = curr_sum
    if (curr_sum > k) :
        r -=1
    else:
        l += 1
    
output(str(maxSum))