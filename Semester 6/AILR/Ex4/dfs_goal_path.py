def dfs(graph, start, end, path=[], visited=set()):
    path = path + [start]
    visited.add(start)
    print(f"Visiting node: {start}")
    if start == end:
        print(f"Goal path found: {' -> '.join(path)}")
        return path
    if start not in graph:
        return None

    for neighbor in graph[start]:
        if neighbor not in visited:
            result = dfs(graph, neighbor, end, path, visited)
            if result:
                return result
    return None


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
dfs(graph, start_node, end_node)

# #dfs with start and end point
# def dfs(graph,start,end,visited=set()):
#   visited.add(start)
#   if start==end:
#     print(f"Path Found : {visited}")
#     return
#   for next in graph[start]:
#     if next not in visited:
#       dfs(graph,next,end,visited)
# graph = {0 : [1,2],1 : [3,4],2 : [0],
#   	      3 : [1],4 : [2,3]}
# start = int(input("Enter the Starting Node :"))
# end = int(input("Enter the Ending Node :"))
# dfs(graph,start,end)