from collections import deque
def bfs(graph, start, goal):
    queue = deque([start])
    visited = set()  
    
    while queue:
        current_node = queue.popleft()
        if current_node == goal:
            print(f"Goal node {goal} found!")
            return True
        visited.add(current_node)
        for neighbor in graph.get(current_node, []):
            if neighbor not in visited:
                queue.append(neighbor)
    print("Goal node not found.")
    return False
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['G'],
    'F': [],
    'G': []
}
bfs(graph, 'A', 'G')
bfs(graph,'A','Z')