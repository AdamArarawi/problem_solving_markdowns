import sys
input = sys.stdin.readline
print = sys.stdout.write

result = []
def subsets(n, k, i,curr :list = []):
    if len(curr) == k:
        result.append(curr[:])
        return
    if i > n:
        return
    curr.append(i)
    subsets(n,k,i+1,curr)
    curr.pop()
    subsets(n,k,i+1,curr)



n,k = map(int,input().split())
subsets(n,k,1)
print(str(result))