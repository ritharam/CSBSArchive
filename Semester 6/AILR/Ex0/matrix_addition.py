#Matrix Addition 
A = [[1,1],[1,1]]
B = [[2,2],[2,2]]
C = [[0,0],[0,0]]
for i in range(0,2):
    for j in range(0,2):
        C[i][j] = A[i][j] + B[i][j]
print(C)