import sys

a = [[0]*3 for _ in range(5)]
a[0][1] = 5

# must in str()
sys.stdout.write(str(a) + '\n')

a = [10,20,30,40,50,60,70]

# [start : end : step]
sys.stdout.write(str(a[::-1]) + '\n')

for val, i in enumerate(a):
    print(val, i)