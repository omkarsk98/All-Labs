class Graph(object):
    def __init__(self, N, M):
        self.N, self.M = N, M  # set no. of nodes and no. of edges for the graph
        self.alist = {key: list() for key in range(1, N+1)}
        for index in range(M):
            t, h = map(int, input("Space separated edge in terms of from and to:").split())
            self.alist[t].append(h)
            self.alist[h].append(t)

    def bfs(self, source):
        distances = {key: -1 for key in range(1, self.N+1)}
        to_explore = set([source])
        current_distance = 0
        while to_explore:
            next_nodes = set()
            for tnode in to_explore:
                if distances[tnode] == -1:
                    distances[tnode] = current_distance
                    next_nodes.update(self.alist[tnode])
            to_explore = next_nodes
            current_distance += 1
        self.distances = distances

    def answer(self, source):
        self.bfs(source)
        for index in range(1, N+1):
            if index == source:
                continue
            elif self.distances[index] == -1:
                print(-1, end=" ")
            else:
                print(6 * self.distances[index], end=" ")
        print()


T = int(input("Number of Graphs:"))  # for number of queries
for index in range(T):
    print("Space separated inputs for no. of nodes and no. of columns for graph", index+1, ":", end="")
    # no. of nodes, no. of edges
    N, M = map(int, input().split())
    graph = Graph(N, M)
    source = int(input("Source for this graph:"))
    graph.answer(source)
