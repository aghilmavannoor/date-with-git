from queue import PriorityQueue

v = 14
graph = [[] for i in range(v)]

def best_first_search(actual_src, target, n): 
    visited = [False] * n 
    pq = PriorityQueue() 
    pq.put((0, actual_src)) 
    visited[actual_src] = True 

    while not pq.empty(): 
        u = pq.get()[1]  
        print(u, end=" ") 
        if u == target: 
            break 

        for v, c in graph[u]: 
            if not visited[v]: 
                visited[v] = True 
                pq.put((c, v)) 

def addedge(x, y, cost): 
    graph[x].append((y, cost)) 
    graph[y].append((x, cost)) 

addedge(0, 1, 3)
addedge(0, 2, 9)
addedge(0, 3, 5)
addedge(1, 4, 9)
addedge(1, 2, 8)
addedge(2, 6, 12)
addedge(2, 7, 14)
addedge(3, 8, 7)
addedge(8, 9, 5)
addedge(8, 10, 6)
addedge(9, 11, 1)
addedge(9, 12, 10)
addedge(9, 13, 2)

source = 0
target = 9
print("Best-First Search Path:")
best_first_search(source, target, v)
