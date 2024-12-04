print("$$")

class AOStarNode:
    def __init__(self, state):  # Fixed the constructor to use double underscores "__init__"
        self.state = state
        self.f = float('inf')  # Estimated total cost (g + heuristic)
        self.g = float('inf')  # Cost from the start node to this node
        self.parent = None  # Parent node for path reconstruction

def heuristic(state, goal_state):
    """Heuristic function for AO* (can be customized)."""
    return 0 if state == goal_state else 1  # Simple heuristic: 0 if goal, 1 otherwise

def ao_star_search(graph, start, goal):
    open_list = [start]  # Initialize the open list with the start node
    start.f = 0  # Initialize the f-value of the start node
    start.g = 0  # Initialize the g-value of the start node

    while open_list:
        # Select the node with the lowest f-value
        current = min(open_list, key=lambda node: node.f)
        open_list.remove(current)

        # Check if the goal is reached
        if current.state == goal.state:
            path = []
            while current:
                path.append(current.state)
                current = current.parent
            return path[::-1]  # Return the reversed path

        # Explore neighbors of the current node
        for neighbor_state in graph[current.state]:
            neighbor = AOStarNode(neighbor_state)
            neighbor.g = current.g + 1  # Update g-value
            neighbor.f = neighbor.g + heuristic(neighbor_state, goal.state)  # Update f-value
            neighbor.parent = current  # Set the parent for path reconstruction

            # Add neighbor to the open list if not already there or if a better path is found
            if not any(node.state == neighbor.state for node in open_list):
                open_list.append(neighbor)

    return None  # Return None if the goal is unreachable

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['D'],
    'D': ['E'],
    'E': []
}

start_node = AOStarNode('A')  # Define the start node
goal_node = AOStarNode('E')  # Define the goal node
path_found = ao_star_search(graph, start_node, goal_node)

if path_found:
    print("Shortest path found:", path_found)
else:
    print("Goal is unreachable.")
