import math
def minmax(d, nI, maxp, vals, td, bf):
    if d == td:
        return vals[nI]
    if maxp:
        best = -10000
        for j in range(bf):
            child = nI * bf + j
            if child < len(vals):
                best = max(best, minmax(d + 1, child, False, vals, td, bf))
        return best
    else:
        best = 10000
        for j in range(bf):
            child = nI * bf + j
            if child < len(vals):
                best = min(best, minmax(d + 1, child, True, vals, td, bf))
        return best

vals = list(map(int, input("Enter scores: ").split()))
bf = int(input("Enter branching factor: "))
maxp = int(input("Maximizer (1) or Minimizer (0): "))
td = math.ceil(math.log(len(vals), bf))
print("Optimal value:", minmax(0, 0, bool(maxp), vals, td, bf))