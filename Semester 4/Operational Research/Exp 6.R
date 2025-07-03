# LPP using Sensitive Analysis

library(lpSolve)

solve_lp <- function(obj,mat,dir,rhs) {
  lp_solution <- lp("max",obj,mat,dir,rhs)
  if(lp_solution$status == 0){
    cat("Optimal Solution\n")
    cat("x1 :",lp_solution$solution[1],"\n")
    cat("x2 :",lp_solution$solution[2],"\n")
    cat("x3 :",lp_solution$solution[3],"\n")
    cat("x4 :",lp_solution$solution[4],"\n")
    cat("Maximum Cost :",lp_solution$objval,"\n")
    cat("Sensitivity Analysis for RHS","\n")
    for(i in 1:length(rhs)){
      cat("constraint ",i," :",lp_solution$pi[i],"\n")
    }
  }else if(lp_solution$status == 2){
    cat("Problem is infeasible","\n")
  }else{
    cat("Error in solving the LPP")
  }
  return(lp_solution)
}
obj <- c(2,1,4,-1,0,0,0)
mat <- matrix(c(1,2,1,-3,1,0,0,
                0,-1,1,2,0,1,0,
                2,7,-5,-10,0,0,1),ncol=7,byrow=TRUE)
rhs <- c(8,0,21)
dir <- c("<=","<=","<=")
og = solve_lp(obj,mat,dir,rhs)

new_rhs <- c(8,11,21)
new = solve_lp(obj,mat,dir,new_rhs)

new_rhs = c(3,-2,4)
new = solve_lp(obj,mat,dir,new_rhs)

------------------------------------------------------------------------------

library(lpSolve)

solve_lp <- function(obj,mat,dir,rhs) {
  lp_solution <- lp("max",obj,mat,dir,rhs)
  if(lp_solution$status == 0){
    cat("Optimal Solution\n")
    cat("x1 :",lp_solution$solution[1],"\n")
    cat("x2 :",lp_solution$solution[2],"\n")
    cat("x3 :",lp_solution$solution[3],"\n")
    cat("Maximum Cost :",lp_solution$objval,"\n")
    cat("Shadow prices (Sensitivity Analysis for RHS)","\n")
    for(i in 1:length(rhs)){
      cat("constraint ",i," :",lp_solution$pi[i],"\n")
    }
    cat("Reduced Costs (Sensitivity Analysis for objective function coefficients)","\n")
    for(j in 1:length(obj)){
      cat("coefficient ",j," :",lp_solution$rc[i],"\n")
    }
  }else if(lp_solution$status == 2){
    cat("Problem is infeasible","\n")
  }else{
    cat("Error in solving the LPP")
  }
  return(lp_solution)
}

obj <- c(4,6,2,0,0)
mat <- matrix(c(1,1,1,1,0,
                1,4,7,0,1),ncol=5,byrow=TRUE)
rhs <- c(3,9)
dir <- c("<=","<=")
og = solve_lp(obj,mat,dir,rhs)

new_obj_c3 <- c(4,6,12,0,0)
new = solve_lp(new_obj_c3,mat,dir,rhs)
cat("Change in maximum value of z for c3 : ", new$objval - og$objval,"\n")

new_obj_all = c(2,8,4,0,0)
new = solve_lp(new_obj_all,mat,dir,rhs)
cat("Change in maximum value of z for (c1,c2,c3) : ", new$objval - og$objval,"\n")
