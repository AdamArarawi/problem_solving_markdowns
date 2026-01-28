import sys
import heapq
input = sys.stdin.readline

def dijkstra(start, n, graph):
    INF = 10**18
    dist = [INF] * (n + 1)
    parent = [-1] * (n + 1)
    dist[start] = 0

    pq = [(0, start)]

    while pq:
        curr_dist, u = heapq.heappop(pq)
        if curr_dist > dist[u]:
            continue
        
        for v, w in graph[u]:
            if curr_dist + w < dist[v]:
                dist[v] = curr_dist + w
                parent[v] = u
                heapq.heappush(pq, (dist[v], v))
    
    return dist, parent

def get_path(parent, start, target):
    path = []
    cur = target
    while cur != -1:
        path.append(cur)
        cur = parent[cur]
    path.reverse()
    return path if path[0] == start else []

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))  # directed
    # graph[v].append((u, w))

start = int(input())
target = int(input())

dist, parent = dijkstra(start, n, graph)
path = get_path(parent, start, target)

if path:
    print(f"Shortest distance from {start} to {target}: {dist[target]}")
    print(f"Path: {' -> '.join(map(str, path))}")
else:
    print(f"No path from {start} to {target}")
