graph={
    '5':['8','3','6'],
    '8':['1','2','22'],
    '2':[],
    '3':[],
    '6':['24','66'],
    '1':[],
    '22':[],
    '24':['33'],
    '66':[],
    '33':[],
}
visited=[]
queue=[]
def bfs(visited,graph,node):
    visited.append(node)
    queue.append(node)
    while queue:
        m=queue.pop(0)
        print(m,end='  ')
        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
                
print("following is the bfs")
bfs(visited,graph,'8')