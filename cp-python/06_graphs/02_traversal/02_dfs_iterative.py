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
st = deque()

st.append(start)
visited[start] = True

while st:
    node = st.pop()
    print(str(node) + " ")
    
    for nxt in graph[node]:
        if not visited[nxt]:
            visited[nxt] = True
            st.append(nxt)
