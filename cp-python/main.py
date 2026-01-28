
def check(s):
    n = len(s)
    if n % 2 != 0:
        return False
    
    i = 0
    j = n // 2

    while j < n:
        if s[i] != s[j]:
            return False
        i += 1
        j += 1
        
    return True

s = input()

print(check(s))