import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.parent = list(range(n+1))
        self.rank = [0] * (n+1)
    
    def find(self, i):
        while self.parent[i] != i:
            self.parent[i] = self.parent[self.parent[i]]
            i = self.parent[i]
        return self.parent[i]

    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)

        if root_i != root_j:
            if self.rank[root_i] < self.rank[root_j] :
                self.parent[root_i] = root_j
            
            elif self.rank[root_i] > self.rank[root_j] :
                self.parent[root_j] = root_i
            else:
                self.parent[root_i] = root_j
                self.rank[root_j] += 1
            return True
        return False


n, m = map(int, input().split())
dsu = DSU(n)

components = n

for _ in range(m):
    u, v = map(int, input().split())
    done = dsu.union(u,v)

    if done:
        components -= 1

print(components)




