from collections import deque
import sys

input = sys.stdin.readline
write = sys.stdout.write

n, m = map(int,input().split())
graph = [[] for _ in range(n)]

indegree = [0] * n

for _ in range(m):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    indegree[v] += 1

q = deque()

for i, deg in enumerate(indegree):
    if deg == 0:
        q.append(i)

topo = []

while q:
    node = q.popleft()
    topo.append(node + 1)
    
    for nxt in graph[node]:
        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            q.append(nxt)

if len(topo) != n:
    write("IMPOSSIBLE")
else:
    write(" ".join(map(str, topo)))
