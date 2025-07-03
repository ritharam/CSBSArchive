def bfs(graph, start, goal):
    q = [(start, [start])]
    visited = set()
    trav_seq = []

    while q:
      node, path = q.pop(0)
      if node not in visited:
        visited.add(node)
        trav_seq.append(node)

        if node == goal:
          return trav_seq, path

        for adj in graph.get(node, []):
          if adj not in visited:
            q.append((adj, path + [adj]))
    return trav_seq, None

# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
# }

graph = {
    'M': ['N', 'O', 'P'],
    'N': ['Q', 'R'],
    'O': ['S', 'T', 'V'],
    'P': ['X', 'Y'],
    'Q': [],
    'R': [],
    'S': [],
    'T': [],
    'V': [],
    'X': [],
    'Y': []
}

start_node = 'M'
end_node = 'V'

traversal, path = bfs(graph, start_node, end_node)

if path:
    print("BFS Traversal Sequence:", traversal)
    print("Solution Path:", path)
else:
    print("BFS Traversal Sequence:", traversal)
    print("No path found from", start_node, "to", end_node)