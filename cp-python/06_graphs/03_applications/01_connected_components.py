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

visited = [False for _ in range(n + 1)]

num_components = 0

for i in range(1, n + 1):
    if not visited[i]:
        num_components += 1
        q = deque()
        q.append(i)
        visited[i] = True
        while q:
            node = q.popleft()
            for j in graph[node]:
                if not visited[j]:
                    q.append(j)
                    visited[j] = True


print(str(num_components))