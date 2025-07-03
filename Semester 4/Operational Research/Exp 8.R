#Assignment Problem

library(lpSolve)
A = matrix(c(11,8,9,
             14,10,6,
             6,11,7),3,3,byrow=TRUE)
A
lp.assign(A)
lp.assign(A)$solution