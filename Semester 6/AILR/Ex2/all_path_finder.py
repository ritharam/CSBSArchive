def all_paths(graph, start, end, path=None):
    if path is None:
        path = []
    path = path + [start]  
    if start == end:
        return [path]
    if start not in graph:
        return []
   
    paths = []
    for neighbor in graph[start]:
        if neighbor not in path:
            new_paths = all_paths(graph, neighbor, end, path)
            for np in new_paths:
                paths.append(np)
    return paths

# def main():
#     n = int(input("Enter the number of vertices: "))
#     graph = {}
#     for i in range(n):
#         vertex = input(f"Enter the name of vertex {i+1}: ")
#         adjacency = []
#         print(f"Enter neighbors of vertex '{vertex}' one by one.")
#         print("Type 'no' when you're done adding neighbors.\n")
       
#         while True:
#             neighbor = input(f"   Neighbor of {vertex}: ")
#             if neighbor.lower() == 'no':
#                 break
#             adjacency.append(neighbor)
       
#         graph[vertex] = adjacency
   
#     start_node = input("Enter start node: ")
#     end_node   = input("Enter goal (end) node: ")

#     result_paths = all_paths(graph, start_node, end_node)
#     print(f"\nAll paths from {start_node} to {end_node}:")
#     for p in result_paths:
#         print(" -> ".join(p))

# if __name__ == "__main__":
#     main()

# # 1.a all path finder for given graph
# def all_paths(graph, start, end, path=[]):
#     path = path + [start]
#     if start == end:
#         return [path]
#     if start not in graph:
#         return []
#     paths = []
#     for node in graph[start]:
#         if node not in path:
#             new_paths = all_paths(graph, node, end, path)
#             for new_path in new_paths:
#                 paths.append(new_path)
#     return paths
graph = {
    '1': ['2', '3'],
    '2': ['4','1'],
    '3': ['1','4','5'],
    '4': ['2','3','5'],
    '5': ['3','4']
}
start_node = '1'
end_node = '4'
result_paths = all_paths(graph, start_node, end_node)
print(f"All paths from {start_node} to {end_node}:")
for path in result_paths:
    print(path)
