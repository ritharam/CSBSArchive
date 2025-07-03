import constraint
problem=constraint.Problem()
problem.addVariable('x', [4,5,6])
problem.addVariable('y', range(20))

def our_constraint(x,y):
  if x+y>=20:
    return True

problem.addConstraint(our_constraint, ['x','y'])
solutions=problem.getSolutions()
length=len(solutions)
print("(x,y) =\n", end="")
for index, solution in enumerate (solutions):
  print("({},{})".format(solution ['x'], solution['y']), end="")
  if(index==length-1):
    break
  print(",")
print("}")


# import constraint

# problem = constraint.Problem()

# problem.addVariable('S', range(1, 10))  # S cannot be 0
# problem.addVariable('E', range(10))
# problem.addVariable('N', range(10))
# problem.addVariable('D', range(10))
# problem.addVariable('M', range(1, 10))  # M cannot be 0
# problem.addVariable('O', range(10))
# problem.addVariable('R', range(10))
# problem.addVariable('Y', range(10))

# problem.addConstraint(constraint.AllDifferentConstraint())

# def sum_constraint(S, E, N, D, M, O, R, Y):
#     send = 1000 * S + 100 * E + 10 * N + D
#     more = 1000 * M + 100 * O + 10 * R + E
#     money = 10000 * M + 1000 * O + 100 * N + 10 * E + Y
#     return send + more == money

# problem.addConstraint(sum_constraint, ['S', 'E', 'N', 'D', 'M', 'O', 'R', 'Y'])

# solutions = problem.getSolutions()

# for solution in solutions:
#   print(solution)

# prompt: Cryptarithmetic problem
# TWO + TWO = FOUR

# import constraint

# problem = constraint.Problem()

# problem.addVariable('T', range(1, 10))  # T cannot be 0
# problem.addVariable('W', range(10))
# problem.addVariable('O', range(10))
# problem.addVariable('F', range(1, 10))  # F cannot be 0
# problem.addVariable('U', range(10))
# problem.addVariable('R', range(10))

# problem.addConstraint(constraint.AllDifferentConstraint())

# def sum_constraint(T, W, O, F, U, R):
#     two = 100 * T + 10 * W + O
#     four = 1000 * F + 100 * O + 10 * U + R
#     return 2 * two == four

# problem.addConstraint(sum_constraint, ['T', 'W', 'O', 'F', 'U', 'R'])

# solutions = problem.getSolutions()

# for solution in solutions:
#   print(solution)
