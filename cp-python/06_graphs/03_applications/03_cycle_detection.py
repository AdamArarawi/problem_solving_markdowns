from collections import defaultdict, deque
import sys

input = sys.stdin.readline
print = sys.stdout.write

def has_cycle(n, graph, start):
    visited = [False] * (n + 1)
    parent = [None] * (n + 1)
    q = deque()
    
    q.append(start)
    visited[start] = True
    
    while q:
        node = q.popleft()
        for nxt in graph[node]:
            if not visited[nxt]:
                visited[nxt] = True
                parent[nxt] = node
                q.append(nxt)
            elif parent[node] != nxt:
                return True
    return False

n, m = map(int, input().split())
graph = defaultdict(list)

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

print(str(has_cycle(n, graph, 1)))
