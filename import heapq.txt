import heapq

class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0  # Cost from start to current node
        self.h = 0  # Heuristic cost estimate to goal
        self.f = 0  # Total cost (g + h)

    def __eq__(self, other):
        return self.position == other.position

    def __lt__(self, other):
        return self.f < other.f

def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star(graph, start, end):
    open_list = []
    closed_list = set()
    start_node = Node(start)
    end_node = Node(end)
    heapq.heappush(open_list, start_node)

    while open_list:
        current_node = heapq.heappop(open_list)
        closed_list.add(current_node.position)

        if current_node == end_node:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]

        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        for offset in neighbors:
            neighbor_position = (current_node.position[0] + offset[0], current_node.position[1] + offset[1])
            if neighbor_position not in graph or neighbor_position in closed_list:
                continue

            neighbor_node = Node(neighbor_position, current_node)
            neighbor_node.g = current_node.g + 1
            neighbor_node.h = heuristic(neighbor_node.position, end_node.position)
            neighbor_node.f = neighbor_node.g + neighbor_node.h

            if any(open_node for open_node in open_list if neighbor_node == open_node and neighbor_node.g > open_node.g):
                continue

            heapq.heappush(open_list, neighbor_node)

    return None

# Example usage
graph = {
    (0, 0): 1, (0, 1): 1, (0, 2): 1,
    (1, 0): 1, (1, 1): 1, (1, 2): 1,
    (2, 0): 1, (2, 1): 1, (2, 2): 1
}
start = (0, 0)
end = (2, 2)

path = a_star(graph, start, end)
print("Path found:", path)
