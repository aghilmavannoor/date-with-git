import heapq
def a_star_search(graph, start, goal, heuristic):
  open_set = [(0 + heuristic(start, goal), start, [start])]
  closed_set = set()
  while open_set:
    f_score, current, path = heapq.heappop(open_set)
    if current == goal:
      return path
    closed_set.add(current)
    for neighbor, cost in graph[current].items():
      if neighbor in closed_set:
        continue
      tentative_g_score = f_score - heuristic(current, goal) + cost
      if neighbor not in [node for _, node, _ in open_set] or tentative_g_score < f_score:
        new_f_score = tentative_g_score + heuristic(neighbor, goal)
        heapq.heappush(open_set, (new_f_score, neighbor, path + [neighbor]))
  return None
graph = {
    1: {2: 2, 3: 4},
    2: {1: 2, 4: 1},
    3: {1: 4, 5: 3},
    4: {2: 1, 6: 5},
    5: {3: 3, 6: 2},
    6: {4: 5, 5: 2}
}
def manhattan_distance(node, goal):
  return abs(node // 2 - goal // 2) + abs(node % 2 - goal % 2)
start_node = 1
goal_node = 6
path = a_star_search(graph, start_node, goal_node, manhattan_distance)
if path:
  print("Shortest path:", path)
else:
  print("No path found.")