# #Diagonals Shift
# matrix = [
#     [1, 2, 3],
#     [4, 5, 6],
#     [7, 8, 9]]
# n = len(matrix)
# for i in range(n // 2):
#     matrix[i][i], matrix[n-i-1][n-i-1] = matrix[n-i-1][n-i-1], matrix[i][i]
#     matrix[i][n-i-1], matrix[n-i-1][i] = matrix[n-i-1][i], matrix[i][n-i-1]
# for row in matrix:
#     print(row)

import numpy as np

def swap(mat):
    n = len(mat)
    for i in range(n):
        mat[i][i], mat[i][n-1-i] = mat[i][n-1-i], mat[i][i]
    # for i in range(n): 
    #   for j in range(i + 1, n): 
    #     mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
    return mat

mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
swapped = swap(mat)

for row in swapped:
  for col in row:
    print(col,end=" ")
  print()