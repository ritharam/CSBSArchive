import math
visited = []
def minimax(depth, nI, maxp, vals, alpha, beta, td, bf):
    if depth == td:
        return vals[nI]
    if maxp:
        alpha = -10000
        for i in range(bf):
            child = nI * bf + i
            if child < len(vals):
                val = minimax(depth + 1, child, False, vals, alpha, beta, td, bf)
                alpha = max(alpha, val)
                visited.append(val)
                if beta <= alpha:
                    break
        return alpha
    else:
        beta = 10000
        for i in range(bf):
            child = nI * bf + i
            if child < len(vals):
                val = minimax(depth + 1, child, True, vals, alpha, beta, td, bf)
                beta = min(beta, val)
                visited.append(val)
                if beta <= alpha:
                    break
        return beta

vals = list(map(int, input("Enter scores: ").split()))
bf = int(input("Enter branching factor: "))
maxp = int(input("Maximizer (1) or Minimizer (0): "))
td = math.ceil(math.log(len(vals), bf))

print("The optimal value is :", minimax(0, 0, bool(maxp), vals, -10000, 10000, td, bf))
print("Pruned Nodes :", end="")
for i in vals:
    if i not in visited:
        print(i, end=" ")