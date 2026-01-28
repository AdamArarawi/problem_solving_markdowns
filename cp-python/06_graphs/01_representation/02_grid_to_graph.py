import sys
input = sys.stdin.readline
print = sys.stdout.write

r,c  = map(int,input().split())
x,y = map(int,input().split())
graph = [[(i,j) for j in range(c)] for i in range(r)]

directions = [(0,-1), (-1,0), (1,0), (0,1)]

for dx, dy in directions:
    nx, ny = x + dx, y + dy 
    
    if 0 <= nx < r and 0 <= ny < c:
        print(f"({nx}, {ny})\n")
