import numpy as np

def is_magic_square(M):
    M = np.array(M)
    n = len(M)
    row_sums = np.sum(M, axis=1)
    col_sums = np.sum(M, axis=0)
    main_diag_sum = np.sum(np.diag(M))
    anti_diag_sum = np.sum(np.diag(np.fliplr(M)))

    magic_const = int((n * (n**2 + 1)) / 2)
    return (
        np.all(row_sums == magic_const) and
        np.all(col_sums == magic_const) and
        main_diag_sum == magic_const and
        anti_diag_sum == magic_const
    )
A = [[2, 7, 6], 
     [9, 5, 1], 
     [4, 3, 8]]

if is_magic_square(A):
    print("Magic Square matrix")
else:
    print("Not a Magic Square matrix")


import numpy as np

def is_normal_matrix(M):
  rsum = np.sum(M, axis=1)
  csum = np.sum(M, axis=0)
  n = len(M)
  cons = int((n * (n**2 + 1)) / 2)
  return rsum.min() == rsum.max() == csum.min() == csum.max() == cons

A = [[2, 7, 6], [9, 5, 1], [4, 3, 8]]

if is_normal_matrix(A):
  print("Magic Square matrix")
else:
  print("Not a Magic Square matrix")