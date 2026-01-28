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

start = int(input())

visited = [False] * (n + 1)
parent = [None] * (n + 1)
q = deque()

q.append(start)
visited[start] = True

while q:
    node = q.popleft()
    
    for nxt in graph[node]:
        if not visited[nxt]:
            parent[nxt] = node
            visited[nxt] = True
            q.append(nxt)

for i in range(1, n+1):
    if not visited[i]:
        print(f"Node {i}: Unreachable\n")
        continue
    
    path = []
    curr = i
    while curr is not None:
        path.append(curr)
        curr = parent[curr]
    path.reverse()
    print(f"Node {i} : {len(path)-1} steps, Path: {path}\n")

