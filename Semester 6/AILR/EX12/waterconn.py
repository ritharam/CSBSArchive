def paths(n, cons):
    parent = [0] * (n + 1)
    weight = [0] * (n + 1)
    child = [0] * (n + 1)
    for q, h, t in cons:
        child[q] = h
        weight[q] = t
        parent[h] = q

    def dfs(node, curminw):
        if child[node] == 0:  
            return node, curminw
        minw = min(curminw, weight[node])
        return dfs(child[node], minw)

    path = []
    for node in range(1, n + 1):
        if parent[node] == 0 and child[node]:  
            end_node, min_weight = dfs(node, float('inf'))
            path.append((node, end_node, min_weight))
    return path

n = int(input("Enter the number of nodes (n): "))
p = int(input("Enter the number of connections (p): "))

cons = []
print("Enter the connections (q h t) one by one:")
for _ in range(p):
    q, h, t = map(int, input().split())
    cons.append((q, h, t))

paths = paths(n, cons)
print("Number of independent paths:", len(paths))
for start_node, end_node, min_weight in paths:
    print("Start Node:", start_node, "End Node:", end_node,"Minimum Weight:", min_weight)