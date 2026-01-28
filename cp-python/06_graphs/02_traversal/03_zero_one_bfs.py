from collections import defaultdict, deque
import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())
graph = defaultdict(list)

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start = int(input())

INF = int(1e9)
distance = [INF] * (n + 1)
distance[start] = 0

q = deque()
q.append(start)

while q:
    node = q.popleft()
    
    for nxt, w in graph[node]:
        if distance[node] + w < distance[nxt]:
            distance[nxt] = distance[node] + w
            if w == 0:
                q.appendleft(nxt)  
            else:
                q.append(nxt)     

for i in range(1, n + 1):
    if distance[i] == INF:
        print(f"Node {i}: Unreachable\n")
    else:
        print(f"Node {i}: {distance[i]}\n")
