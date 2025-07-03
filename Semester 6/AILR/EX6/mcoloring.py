#Mcoloring problem
def mcoloring(graph,n,c):
    def issafe(graph,color,v,c):
        for i in range(n):
            if graph[v][i] and color[i]==c:
                return 0
        return 1
    def coloring(graph,color,v,c,answer):
        if v==n:
            answer.append(list(color))
            return
        for i in range(1,c+1):
            if issafe(graph,color,v,i):
                color[v] = i
                coloring(graph,color,v+1,c,answer)
                color[v] = 0
    color = [0]*n
    answer = []
    coloring(graph,color,0,c,answer)
    return answer            
graph = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
n = int(input("Enter the Number of Vertices :"))
c = int(input("Enter the Number of Colors :"))
solution = mcoloring(graph,n,c)
for i in solution:
    print(i)