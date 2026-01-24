# patterns.py
from itertools import accumulate
import operator

def prefix_sum(a):
    return list(accumulate(a))

def suffix_sum(a):
    n = len(a)
    suff = [0] * n
    suff[-1] = a[-1]
    for i in range(n-2, -1, -1):
        suff[i] = suff[i+1] + a[i]
    return suff

def range_sum(pref, l, r):
    return pref[r] - (pref[l-1] if l > 0 else 0)



def build_prefix_product(a):
    return list(accumulate(a, operator.mul))

def build_2d_prefix(grid):
    n = len(grid)
    m = len(grid[0])
    pref = [[0]*m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            pref[i][j] = grid[i][j]
            if i > 0:
                pref[i][j] += pref[i-1][j]
            if j > 0:
                pref[i][j] += pref[i][j-1]
            if i > 0 and j > 0:
                pref[i][j] -= pref[i-1][j-1]

    return pref

def rectangle_sum(pref, x1, y1, x2, y2):
    res = pref[x2][y2]
    if x1 > 0:
        res -= pref[x1-1][y2]
    if y1 > 0:
        res -= pref[x2][y1-1]
    if x1 > 0 and y1 > 0:
        res += pref[x1-1][y1-1]
    return res
