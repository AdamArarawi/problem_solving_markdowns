import sys
from itertools  import accumulate
input = sys.stdin.readline

n,q = map(int,input().split())
a = list(map(int,input().split()))
pref = list(accumulate(a))

for _ in range(q):
    l,r =  map(int,input().split())
    sys.stdout.write(str(pref[r] - (pref[l-1] if l else 0)) + '\n')

sys.stdout.write('-----------------------------------------------\n')

suff = list(accumulate(a[::-1]))[::-1]
max_suffix = max(suff)
sys.stdout.write(str(max_suffix))


sys.stdout.write('\n-----------------------------------------------\n')

k = int(input())
dic = {0: 1}
count = 0
for i in pref:
    count += dic.get(i - k, 0)
    if (dic.get(i)):
        dic[i] += 1
    else:
        dic[i] = 1

sys.stdout.write(str(count))

sys.stdout.write('\n-----------------------------------------------\n')

k = int(input())

for i in range(k-1, n):
    if (i == k-1):
        sys.stdout.write(str(pref[i]))
    else :
        sys.stdout.write(str(pref[i] - pref[i-k]))
    sys.stdout.write('\n')

sys.stdout.write('-----------------------------------------------\n')
    