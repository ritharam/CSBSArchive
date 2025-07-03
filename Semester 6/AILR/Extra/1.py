def dfs(graph, node, visited):
    visited.add(node)
    for neighbor in graph.get(node, []):
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    return visited

# def is_connected(graph):
#     nodes = list(graph.keys())
#     if not nodes:
#         return True
#     visited = set()
#     dfs(graph, nodes[0], visited)
#     return len(visited) == len(nodes)

graph = {
    "A": [],
    
    "B": ["C"],
    "C": ["B"],

    "D": ["E"],
    "E": ["D", "F"],
    "F": ["E"],

    "G": ["H", "I", "J"],
    "H": ["G", "I", "J"],
    "I": ["G", "H", "J"],
    "J": ["G", "H", "I"]
}

# graph = {}
# n = int(input("Enter the number of Nodes: "))

# for _ in range(n):
#     node = input("Enter the node name: ")
#     neighbors = input(f"Enter the neighbors of {node} (comma-separated): ").split(",")
#     neighbors = [neighbor.strip() for neighbor in neighbors]
#     graph[node] = neighbors

# print(graph)
# if is_connected(graph):
#     print("The graph is connected.")
# else:
#     print("The graph is disconnected.")
nodes = ['A','B','C','D','E','F','G','H','I','J']
component = 0
while nodes:
    component+=1
    start = nodes.pop(0)
    visit = set()
    visit = dfs(graph,start,visit)
    print(visit)
    for i in nodes.copy():
        if i in visit:
            nodes.remove(i)
print(component)