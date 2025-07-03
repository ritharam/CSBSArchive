def largest_zero_region(matrix,n):
    visited = [[False] * n for _ in range(n)]    
    def dfs(r, c):
        if r < 0 or r >= n or c < 0 or c >= n:
            return 0
        if visited[r][c] or matrix[r][c]:
            return 0        
        visited[r][c] = True
        size = 1        
        size += dfs(r+1, c)
        size += dfs(r-1, c)
        size += dfs(r, c+1)
        size += dfs(r, c-1)        
        return size
    max_region = 0    
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 0 and not visited[i][j]:
                max_region = max(max_region, dfs(i, j))    
    return max_region
matrix = [
    [1, 0, 0, 1],
    [1, 0, 1, 1],
    [0, 0, 1, 0],
    [1, 1, 1, 0]]
n=4
print("Largest region of 0's:", largest_zero_region(matrix,n))
