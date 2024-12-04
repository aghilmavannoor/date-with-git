class Graph:
    def __init__(self):
        self.graph = {}
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)
    def dfs(self, node, visited):
        visited.add(node)
        print(node, end=" ") 
        for neighbor in self.graph.get(node, []):
            if neighbor not in visited:
                self.dfs(neighbor, visited)
if __name__ == "__main__":
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)
    visited_nodes = set()
    print("DFS starting from node 0:")
    g.dfs(2, visited_nodes)
