import networkx as nx
import matplotlib.pyplot as plt

def display_path(graph, path=None):
    G = nx.DiGraph()

    for node, edges in graph.items():
        for adj, cost in edges:
            G.add_edge(node, adj, weight=cost)
    pos = nx.spring_layout(G) 
    plt.figure(figsize=(8, 6))
    nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=2000, font_size=15, font_weight='bold', edge_color='gray')
    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=12)
    if path:
        path_edges = list(zip(path, path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=2.5)
    plt.title("Uniform Cost Search Path Visualization")
    plt.show()

graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 1), ('E', 3)],
    'C': [('F', 5)],
    'D': [('G', 2)],
    'E': [('G', 1)],
    'F': [('G', 2)],
    'G': []
}

def ucs(graph, start, goal):
    pq = [(0, start, [start])]  # (cost, current_node, path)
    visited = set()
    while pq:
        pq.sort()  
        cost, node, path = pq.pop(0)  
        if node in visited:
            continue
        visited.add(node)
        if node == goal:
            return cost, path  
        for adj, e_cost in graph.get(node, []):
            if adj not in visited:
                pq.append((cost + e_cost, adj, path + [adj]))
    return None

start = 'A'
goal = 'G'
result = ucs(graph, start, goal)
display_path(graph)  

if result:
    totcost, path = result
    print(f"Least cost path from {start} to {goal}: {' -> '.join(path)} with total cost {totcost}")
    display_path(graph, path) 
else:
    print(f"No path found from {start} to {goal}")
