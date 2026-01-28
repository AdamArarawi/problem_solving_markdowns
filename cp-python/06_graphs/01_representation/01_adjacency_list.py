from collections import defaultdict
import sys
input = sys.stdin.readline
print = sys.stdout.write

n,m  = map(int,input().split())
graph = defaultdict(list)

for i in range(m):
    u,v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

for node, neighbors in graph.items():
    print(f"{node} -> {neighbors}\n")