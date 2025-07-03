from collections import deque
import numpy as np

def wet_cotton(mat):
    queue = deque()

    for r in range(len(mat)):
        for c in range(len(mat[0])):
            if mat[r][c] == 2:
                queue.append((r, c))
    while queue:
        dr, dc = queue.popleft()
        for r, c in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nr, nc = dr + r, dc + c
            if (0 <= nr < len(mat) and 0 <= nc < len(mat[0]) and mat[nr][nc] == 1):
                mat[nr][nc] = 2  
                queue.append((nr, nc))  
    return mat

mat = [[2, 0, 1], [1, 1, 2], [0, 1, 0]]
print("Before traversing:")
print(np.matrix(mat))
mat = wet_cotton(mat)  
print("After Traversing:")
print(np.matrix(mat))