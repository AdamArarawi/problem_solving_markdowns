from collections import defaultdict, deque
import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())
graph = defaultdict(list)

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

colors = [None] * (n+1)
can = True

for i in range(1, n+1):
    if colors[i] is None:
        q = deque([i])
        colors[i] = 0 
        while q:
            node = q.popleft()
            for j in graph[node]:
                if colors[j] is None:
                    colors[j] = colors[node] ^ 1
                    q.append(j)
                elif colors[j] == colors[node]:
                    can = False
                    break
            if not can:
                break
    if not can:
        break

if can:
    print("Yes\n")
    for i in range(1, n+1):
        print(f"Node {i}: {colors[i]}\n")
else:
    print("No")
