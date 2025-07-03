# def dfs_traverse(graph, start, path=None, visited=None):
#     if path is None:
#         path = []
#     if visited is None:
#         visited = set()
    
#     path.append(start)
#     visited.add(start)
#     print(f"Visiting node: {start}")
    
#     for neighbor in graph.get(start, []):
#         if neighbor not in visited:
#             dfs_traverse(graph, neighbor, path, visited)
    
#     return path

def dfs(graph, start, goal):
    stack = [(start, [start])]
    visited = set()
    trav_seq = []

    while stack:
        node, path = stack.pop() 
        if node not in visited:
            visited.add(node)
            trav_seq.append(node)

            if node == goal:
                return trav_seq, path
            
            for adj in reversed(graph.get(node, [])):
                if adj not in visited:
                    stack.append((adj, path + [adj]))
    return trav_seq, None

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

traversal, path = dfs(graph, start_node, end_node)

if path:
    print("DFS Traversal Sequence:", traversal)
    print("Solution Path:", path)
else:
    print("DFS Traversal Sequence:", traversal)
    print("No path found from", start_node, "to", end_node)



