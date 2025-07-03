library(lpSolve)
M <- 1000
obj <- c(2,4,3,0,-M)
mat <- matrix(c(1,1,2,1,0,
                2,3,4,0,1),ncol =5, byrow =TRUE)
rhs<-c(5,12)
direction<- c("<=","=")
lp_solution <- lp("max",obj, mat, direction, rhs)
cat("Optimal solution:\n")
cat("x1:", lp_solution$solution[1], "\n")
cat("x2:", lp_solution$solution[2], "\n")
cat("x3:", lp_solution$solution[3], "\n")
cat("Maximum cost:", lp_solution$objval, "\n")

library(lpSolve)
M <- 1000
obj <- c(6,4,0,0,-M)
mat <- matrix(c(2,3,1,0,0,
                3,2,0,1,0,
                1,1,0,0,-1),ncol =5, byrow =TRUE)
rhs<-c(30,24,3)
direction<- c("<=","<=",">=")
lp_solution <- lp("max",obj, mat, direction, rhs)
cat("Optimal solution:\n")
cat("x1:", lp_solution$solution[1], "\n")
cat("x2", lp_solution$solution[2], "\n")
cat("Maximum cost:", lp_solution$objval, "\n")

library(lpSolve)
M <- 1000
obj <- c(1,2,0,0,-M)
mat <- matrix(c(1,-1,-1,0,1,
                2,1,0,1,1),ncol =5, byrow =TRUE)
rhs<-c(3,10)
direction<- c(">=","<=")
lp_solution <- lp("max",obj, mat, direction, rhs)
cat("Optimal solution:\n")
cat("x1:", lp_solution$solution[1], "\n")
cat("x2", lp_solution$solution[2], "\n")
cat("Maximum cost:", lp_solution$objval, "\n")