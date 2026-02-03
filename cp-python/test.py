

n = 5
a = [10, -5, 2, 7, -3]
q = 4
queries = [(1,3), (0, 4), (2, 2), (3, 4)]

pref = [0] * (n)
pref[0] = a[0]

for i in range(1, n):
    pref[i] = pref[i - 1] + a[i]

print(pref)

for l,r in queries:
    if l == 0:
        print(pref[r])
    print(pref[r] - pref[l-1])


from math import comb

a = [1, 1, 1, 1]
n = len(a)

pref = [0] * n
pref[0] = a[0]

for i in range(1, n):
    pref[i] = pref[i - 1] + a[i]

one_count = 0
zeros_count = 0

for x in pref:
    if x % 2 == 1:
        one_count += 1
    else:
        zeros_count += 1

result = comb(zeros_count, 2) + comb(one_count, 2)
print(result)

a = [3, -1, -2, 4, -4]
n = len(a)

pref = 0
freq = {0:1}
count = 0

for i in range(n):
    pref += a[i]

    if pref in freq:
        count += freq[pref]
        freq[pref] += 1
    else:
        freq[pref] = 1

print(count)

a = [2, 3, 1, 6, 4]
n = len(a)

pref = [0] * n
pref[0] = a[0]

for i in range(1, n):
    pref[i] = pref[i - 1] + a[i]


a = [2, 3, 1, 6, 4]
n = len(a)

pref = [0] * n
pref[0] = a[0]

for i in range(1, n):
    pref[i] = pref[i - 1] + a[i]

zero_count = 0
one_count = 0
two_count = 0

for x in pref:
    if x % 3 == 0:
        zero_count += 1
    elif x % 3 == 1:
        one_count += 1
    else:
        two_count += 1

result = comb(zero_count, 2) + comb(one_count, 2) + comb(two_count, 2)
print(result)

from collections import defaultdict

a = [1, -1, 1, -1, 1]
n = len(a)

freq = defaultdict(int)

pref = 0
count = 0

freq[0] = 1

for x in a:
    pref += x
    count += freq[pref - 1]  
    freq[pref] += 1

pref(count)