library(lpSolve)

obj = c(2,3,4)
mat = matrix(c(3,2,1,
               2,3,3,
               1,1,-1),ncol=3, byrow = TRUE)
dir = c("<=","<=",">=")
rhs = c(10,15,4)

num_artificial = ncol(mat)
phase1 = c(rep(0,length(obj)),rep(1,num_artificial))

result_phase1 = lp(direction = "max",objective.in = phase1, const.mat = mat,const.dir = dir,const.rhs = rhs)

if (result_phase1$status != 0 || any(is.na(result_phase1$solution))) {
  cat("No f sol phase 1.")
} else {
  cat("Sol Phase 1.")
  result_phase2 = lp("max",obj,mat,dir,rhs)
  
  if (result_phase2$status != 0 || any(is.na(result_phase2$solution))) {
    cat("No f sol phase 2.")
  } else {
    cat("Sol Phase 2.")
    cat("Obj :",result_phase2$objval)
    cat("Values : ", result_phase2$solution[1:length(obj)])
  }
}

library(lpSolve)

c <- c(6,21)
A <- matrix(c(1,2,
              1,4),ncol = 2, byrow = TRUE) 
b <- c(3,4)
const.dir <- c(">=", ">=")

num_artificial <- ncol(A)
c_phase1 <- c(rep (0, length(c)), rep(1, num_artificial))
print(c_phase1)

result_phase1 <- lp(direction = "min", objective.in = c_phase1, const.mat = A, const.dir = const.dir, const.rhs = b)

if (result_phase1$status != 0 || any(is.na(result_phase1$solution))) {
  cat("No feasible solution found in Phase 1.\n")
} else{
  cat("Feasible solution found in Phase 1.\n") 
  
  x_phase1 <- result_phase1$solution[1:length(c)]
  c_phase2 <- c
  A_phase2 <- A[,1:length(c)]
  b_phase2 <- b
  
  #c_phase2[1: length (c)] <- c
  
  result_phase2 <- lp(direction = "min", objective.in = c_phase2, const.mat = A_phase2, const.dir = const.dir, 
                      const.rhs = b_phase2)
  
  if (result_phase2$status != 0 || any(is.na(result_phase2$solution))) { 
    cat("No feasible solution found in Phase 2.\n")
  } else {
    cat("optimal solution found in Phase 2.\n")
    cat("\nFinal solution:\n")
    cat("objective value:", result_phase2$objval, "\n")
    cat("Optimal values of variables:", result_phase2$solution[1: length(c)], "\n")
  }
}