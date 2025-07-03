import heapq

def ucs(graph, start, goal):
    pq = [(0, start)]
    visited = {start: (0, None)}
    
    while pq:
      curcost, curnode = heapq.heappop(pq)
      if curnode == goal:
        path = []
        while curnode is not None:
          path.append(curnode)
          curnode = visited[curnode][1]
        return curcost, list(reversed(path))
        
      for adj, cost in graph.get(curnode, []):
        totcost = curcost + cost
        if adj not in visited or totcost < visited[adj][0]:
          visited[adj] = (totcost, curnode)
          heapq.heappush(pq, (totcost, adj))
    return None

graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 1), ('E', 3)],
    'C': [('F', 5)],
    'D': [('G', 2)],
    'E': [('G', 1)],
    'F': [('G', 2)],
    'G': []
}

start = 'A'
goal = 'G'
result = ucs(graph, start, goal)
if result:
    totcost, path = result
    print(f"Least cost path from {start} to {goal}: {' -> '.join(path)} with total cost {totcost}")
else:
    print(f"No path found from {start} to {goal}")