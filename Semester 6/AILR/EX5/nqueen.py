def nqueen(n):
    def issafe(mat, row, col):
        for i in range(row):
            if mat[i][col]:
                return 0
        for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
            if mat[i][j]:
                return 0
        for i, j in zip(range(row - 1, -1, -1), range(col + 1, n, 1)):
            if mat[i][j]:
                return 0
        return 1    
    def placequeen(mat, row, solutions):
        if row == n:
            ans = []
            for i in range(n):
                for j in range(n):
                    if mat[i][j]:
                        ans.append(j + 1)
            solutions.append(ans)
            return        
        for i in range(n):
            if issafe(mat, row, i):
                mat[row][i] = 1
                placequeen(mat, row + 1, solutions)
                mat[row][i] = 0    
    mat = [[0] * n for _ in range(n)]
    solutions = []
    placequeen(mat, 0, solutions)
    return solutions
n = int(input("Enter the size of chess Board :"))
ans = nqueen(n)
for solution in ans:
    print(solution)

# N-Queen Problem
# def issafe (board, row, col):
#   for x in range(col):
#     if board[row] [x]==1:
#       return False
#   for x,y in zip(range (row,-1,-1), range(col,-1,-1)):
#     if board[x][y]==1:
#       return False
#   for x,y in zip (range (row, N,1), range (col,-1,-1)):
#     if board[x][y]==1:
#       return False
#   return True
# def solvenqueens (board,col):
#   if(col==N):
#     print(board)
#     return True
#   for i in range(N):
#     if(issafe (board, i,col)):
#       board[i][col]=1
#       if(solvenqueens (board, col+1)):
#         return True
#       board[i][col]=0

# N=4
# board=[[0 for x in range (N)] for y in range(N)]
# solvenqueens (board, 0)