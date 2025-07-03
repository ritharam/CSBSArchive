# # graph = {
# #     'A': [('B', 1), ('C', 4)],
# #     'B': [('A', 1), ('C', 2), ('D', 5)],
# #     'C': [('A', 4), ('B', 2), ('D', 1)],
# #     'D': [('B', 5), ('C', 1)]
# # }
# # md = {
# #     'A': 3,
# #     'B': 2,
# #     'C': 1,
# #     'D': 0
# # }
# md = {
#     "Arad": 366,
#     "Bucharest": 0,
#     "Craiova": 160,
#     "Drobeta": 242,
#     "Eforie": 161,
#     "Fagaras": 178,
#     "Giurgiu": 77,
#     "Hirsova": 151,
#     "Iasi": 226,
#     "Lugoj": 244,
#     "Mehadia": 241,
#     "Neamt": 234,
#     "Oradea": 380,
#     "Pitesti": 98,
#     "Rimnicu Vilcea": 193,
#     "Sibiu": 253,
#     "Timisoara": 329,
#     "Urziceni": 80,
#     "Vaslui": 199,
#     "Zerind": 374
# }
# graph = {
#     'Arad': [('Zerind', 75), ('Sibiu', 140), ('Timisoara', 118)],
#     'Zerind': [('Arad', 75), ('Oradea', 71)],
#     'Oradea': [('Zerind', 71), ('Sibiu', 151)],
#     'Sibiu': [('Arad', 140), ('Oradea', 151), ('Fagaras', 99), ('Rimnicu Vilcea', 80)],
#     'Timisoara': [('Arad', 118), ('Lugoj', 111)],
#     'Lugoj': [('Timisoara', 111), ('Mehadia', 70)],
#     'Mehadia': [('Lugoj', 70), ('Drobeta', 75)],
#     'Drobeta': [('Mehadia', 75), ('Craiova', 120)],
#     'Craiova': [('Drobeta', 120), ('Rimnicu Vilcea', 146), ('Pitesti', 138)],
#     'Rimnicu Vilcea': [('Sibiu', 80), ('Craiova', 146), ('Pitesti', 97)],
#     'Fagaras': [('Sibiu', 99), ('Bucharest', 211)],
#     'Pitesti': [('Rimnicu Vilcea', 97), ('Craiova', 138), ('Bucharest', 101)],
#     'Bucharest': [('Fagaras', 211), ('Pitesti', 101), ('Giurgiu', 90), ('Urziceni', 85)],
#     'Giurgiu': [('Bucharest', 90)],
#     'Urziceni': [('Bucharest', 85), ('Hirsova', 98), ('Vaslui', 142)],
#     'Hirsova': [('Urziceni', 98), ('Eforie', 86)],
#     'Eforie': [('Hirsova', 86)],
#     'Vaslui': [('Urziceni', 142), ('Iasi', 92)],
#     'Iasi': [('Vaslui', 92), ('Neamt', 87)],
#     'Neamt': [('Iasi', 87)]
# }
# def a_star(graph,md,start,end):
#     q = []
#     q.append((0,md[start],start,[start]))
#     while q:
#         tc,sc,node,path = min(q, key=lambda x: x[1])
#         q.remove((tc,sc,node,path))
#         if node == end:
#             return path,tc
#         for neighbor,dist in graph[node]:
#             if neighbor not in path:
#                 q.append((tc+dist,tc+dist+md[node],neighbor,path+[neighbor]))
#     print("Path Not Found")
#     return []
# start = input("Enter Start City :")
# path,tc = a_star(graph,md,start,'Bucharest')
# print(f"Path from {start} to Bucharest: {' -> '.join(path)}")
# print(f"Total cost: {tc} km")      

import networkx as nx
import matplotlib.pyplot as plt

# Define the Romania map graph
graph = {
    'Arad': [('Zerind', 75), ('Sibiu', 140), ('Timisoara', 118)],
    'Zerind': [('Arad', 75), ('Oradea', 71)],
    'Oradea': [('Zerind', 71), ('Sibiu', 151)],
    'Sibiu': [('Arad', 140), ('Oradea', 151), ('Fagaras', 99), ('Rimnicu Vilcea', 80)],
    'Timisoara': [('Arad', 118), ('Lugoj', 111)],
    'Lugoj': [('Timisoara', 111), ('Mehadia', 70)],
    'Mehadia': [('Lugoj', 70), ('Drobeta', 75)],
    'Drobeta': [('Mehadia', 75), ('Craiova', 120)],
    'Craiova': [('Drobeta', 120), ('Rimnicu Vilcea', 146), ('Pitesti', 138)],
    'Rimnicu Vilcea': [('Sibiu', 80), ('Craiova', 146), ('Pitesti', 97)],
    'Fagaras': [('Sibiu', 99), ('Bucharest', 211)],
    'Pitesti': [('Rimnicu Vilcea', 97), ('Craiova', 138), ('Bucharest', 101)],
    'Bucharest': [('Fagaras', 211), ('Pitesti', 101), ('Giurgiu', 90), ('Urziceni', 85)],
    'Giurgiu': [('Bucharest', 90)],
    'Urziceni': [('Bucharest', 85), ('Hirsova', 98), ('Vaslui', 142)],
    'Hirsova': [('Urziceni', 98), ('Eforie', 86)],
    'Eforie': [('Hirsova', 86)],
    'Vaslui': [('Urziceni', 142), ('Iasi', 92)],
    'Iasi': [('Vaslui', 92), ('Neamt', 87)],
    'Neamt': [('Iasi', 87)],
}

# Heuristics to Bucharest
md = {
    'Arad': 366, 'Zerind': 374, 'Oradea': 380, 'Sibiu': 253, 'Timisoara': 329,
    'Lugoj': 244, 'Mehadia': 241, 'Drobeta': 242, 'Craiova': 160, 'Rimnicu Vilcea': 193,
    'Fagaras': 178, 'Pitesti': 98, 'Bucharest': 0, 'Giurgiu': 77, 'Urziceni': 80,
    'Hirsova': 151, 'Eforie': 161, 'Vaslui': 199, 'Iasi': 226, 'Neamt': 234
}

# A* search function
def a_star(graph, md, start, end):
    q = [(0, md[start], start, [start])]
    while q:
        tc, sc, node, path = min(q, key=lambda x: x[1])
        q.remove((tc, sc, node, path))
        if node == end:
            return path
        for neighbor, dist in graph[node]:
            if neighbor not in path:
                q.append((tc + dist, tc + dist + md[neighbor], neighbor, path + [neighbor]))
    return []

# Get path using A*
start = 'Arad'
end = 'Bucharest'
astar_path = a_star(graph, md, start, end)

# Build graph for visualization
G = nx.Graph()
for node in graph:
    for neighbor, dist in graph[node]:
        G.add_edge(node, neighbor, weight=dist)

# Plot
pos = nx.spring_layout(G, seed=42)
plt.figure(figsize=(14, 10))
nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', node_size=1000, font_size=10)

# Highlight path
path_edges = list(zip(astar_path, astar_path[1:]))
nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=3)
nx.draw_networkx_nodes(G, pos, nodelist=astar_path, node_color='orange')

plt.title(f"A* Path from {start} to {end}", fontsize=15)
plt.axis('off')
plt.tight_layout()
plt.show()
