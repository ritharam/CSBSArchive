def tic_tac_toe(mat):
    x, o = 0, 0
    coord = []
    for i in range(3):
        for j in range(3):
            if mat[i][j] == 'X':
                x += 1
            elif mat[i][j] == 'O':
                o += 1
            else:
                coord.append([i, j])
    return "Player X" if o > x else "Player O", coord

matrix = [['X', 0, 'O'], [0, 'O', 0], ['X', 0, 'X']]
move, coord = tic_tac_toe(matrix)
print("Next Move Belongs to", move)
print("Available Moves :", coord)
