# DUAL and PRIMAL LPP
#install.packages("lpSolve")
library(lpSolve)

obj.coef <- c(3,2)

mat <- matrix(c(-1,-1,
                1, 1,
                1, 2,
                0, 1), ncol = 2, byrow =TRUE)

dir <- c("<=","<=","<=","<=")
rhs <- c(-1,7,10,3)
primal_solution <- lp("max",obj.coef, mat, dir,rhs)
cat("Primal Solution")
print(primal_solution)
primal_var <- primal_solution$solution
cat("Primal variables values : ")
print(primal_var)
dual_mat <- matrix(c(-1, 1, 1, 0,
                     -1, 1, 2, 1), ncol = 4, byrow =TRUE)

dual_solution <- lp("min", rhs, dual_mat, c(">=",">="), obj.coef)
cat("Dual Solution")
print(dual_solution)
dual_variables <- dual_solution$solution
cat("Dual variables values : ")
print(dual_variables)

----------------------------------------------
  
#install.packages("lpSolve")
library(lpSolve)

obj.coef <- c(2,2)

mat <- matrix(c(2,4,
                1,2,
                2,1), ncol = 2, byrow =TRUE)

dir <- c(">=",">=",">=")
rhs <- c(1,1,1)
primal_solution <- lp("min",obj.coef, mat, dir,rhs)
cat("Primal Solution")
print(primal_solution)
primal_var <- primal_solution$solution
cat("Primal variables values : ")
print(primal_var)
dual_mat <- matrix(c(2,1,1,
                     4,2,1), ncol = 3, byrow =TRUE)
dual_solution <- lp("max", rhs, dual_mat, c("<=","<="), obj.coef)
cat("Dual Solution")
print(dual_solution)
dual_variables <- dual_solution$solution
cat("Dual variables values : ")
print(dual_variables)