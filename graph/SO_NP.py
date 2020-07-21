# https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/
# status: solved


from collections import deque

class graph:
    def __init__(self, noOfVertices, noOfEdges):
        self.noOfEdges = noOfEdges
        self.noOfVertices = noOfVertices
        self.adjlist = {}
        for i in range(1, self.noOfVertices+1):
            self.adjlist[i] = []
    
    def addEdge(self, u, v, bidir=True):
        self.adjlist[u].append(v)
        if bidir:
            self.adjlist[v].append(u)

    def bfs(self, src, visited):
        q = deque()
        # visited = {}
        # for i in range(1, 1+noOfVertices):
        #     visited[i] = False

        q.append(src)
        while(len(q)):
            node = q.popleft()
            for neighbor in self.adjlist[node]:
                if not visited[neighbor]:
                    q.append(neighbor)
                    visited[neighbor] = True

    
    def connectedComponents(self):
        components = 0
        visited = {}
        for i in range(1, 1+self.noOfVertices):
            visited[i] = False

        for i in range(1, 1+self.noOfVertices):
            if not visited[i]:
                self.bfs(i, visited)
                components += 1
        return components



if __name__ == '__main__':
    n, m, k = map(int, input().split())
    g = graph(n, m)
    for i in range(m):
        u, v = map(int, input().split())
        g.addEdge(u,v)

    conn  = g.connectedComponents()
    # print(conn)
    if(conn > k):
        print(-1)
    else:
        print(m-n+k)

    
