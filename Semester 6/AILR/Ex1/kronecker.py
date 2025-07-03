#Kronecker Product Matrix
A = [[1, 2], 
     [3, 4]]
B = [[0, 5], 
     [6, 7]]
m, n = len(A), len(A[0])
p, q = len(B), len(B[0])
result = [[0] * (n * q) for _ in range(m * p)]
for i in range(m):
    for j in range(n):
        for k in range(p):
            for l in range(q):
                result[i * p + k][j * q + l] = A[i][j] * B[k][l]
for row in result:
    print(row)

#Kronecker Product
# import numpy as np

# A = [[1,2],[3,4]]
# B = [[0,2],[3,5]]

# n = len(A)*len(B)

# Res = np.zeros((n,n))
# print(Res)

# Result = np.kron(A,B)
# print(Result)

# for i in range(n):
#   for j in range(n):
#     print(i,j)
#     Res[i][j] = A[i // len(B)][i % len(B)] * B[j // len(A)][j % len(A)]
# print(Res)