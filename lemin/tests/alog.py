from collections import defaultdict


class Cord:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Graph:
    def __init__(self):
        self.nodes = dict()
        self.edges = defaultdict(list)
        self.weights = dict()

    def addNode(self, node, x, y):
        self.nodes[node] = Cord(x, y)

    def addEdge(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)
        self.weights[(u, v)] = (self.nodes[u].x - self.nodes[v].x) ** 2 + (self.nodes[u].y - self.nodes[v].y) ** 2
        self.weights[(v, u)] = (self.nodes[u].x - self.nodes[v].x) ** 2 + (self.nodes[u].y - self.nodes[v].y) ** 2

    def dijsktra(self, init, end):
        short = {init: (None, 0)}
        cur_node = init
        visited = set()
        while cur_node != end:
            visited.add(cur_node)
            dest = self.edges[cur_node]
            weight_to_cur_node = short[cur_node][1]
            for next_node in dest:
                weight = self.weights[(cur_node, next_node)] + weight_to_cur_node
                if next_node not in short:
                    short[next_node] = (cur_node, weight)
                else:
                    current_shortest_weight = short[next_node][1]
                    if current_shortest_weight > weight:
                        short[next_node] = (cur_node, weight)
            next_dest = {node: short[node] for node in short if node not in visited}
            if not next_dest:
                return -1
            cur_node = min(next_dest, key=lambda k: next_dest[k][1])
        path = []
        while cur_node is not None:
            path.append(cur_node)
            next_node = short[cur_node][0]
            cur_node = next_node
        path = path[::-1]
        return path


g = Graph()
g.addNode(0, 1, 0)
g.addNode(1, 13, 0)
g.addNode(2, 5, 0)
g.addNode(3, 9, 0)

g.addEdge(0, 2)
g.addEdge(2, 3)
g.addEdge(3, 1)

print(g.dijsktra(0, 1))
