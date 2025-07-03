# #Matrix Multiplication
# A = [[1,1],[1,1]]
# B = [[2,2],[2,2]]
# C = [[0,0],[0,0]]
# for i in range(len(A)):
#     for j in range(len(B[0])):
#         for k in range(len(B)):
#             C[i][j] += A[i][k] + B[k][j]
# print(C)

import numpy as np

A = [[12, 7, 3],
    [4, 5, 6],
    [7, 8, 9]]

B = [[5, 8, 1, 2],
    [6, 7, 3, 0],
    [4, 5, 9, 1]]


result= [[0,0,0,0],
        [0,0,0,0],
        [0,0,0,0]]

result = np.dot(A,B)

for r in result:
    print(r)

print(len(B))
print(len(B[0]))
