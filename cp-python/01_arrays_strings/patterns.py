def max_element(a):
    return max(a)


def greater_than_avg_count(a):
    n = len(a)
    total = sum(a)
    cnt = 0
    for x in a:
        if x * n > total:
            cnt += 1
    return cnt

def reverse_in_place(a: list):
    a.reverse()


def is_palindrome(a: list):
    n = len(a)
    l, r = 0, n-1
    while l < r:
        if a[l] != a[r]:
            return False
        l += 1; r -= 1
    return True

def rotate_right(a, k):
    k %= len(a)
    a[:] = a[-k:] + a[:-k]
