#Transportation Problem 1 

library(lpSolve)
cm=matrix(c(2,2,3,
          4,1,2,
          1,3,1),nrow=3,byrow = TRUE)
print("cost matrix")
print(cm)
row_signs=rep("<=",3)
row_rhs=c(10,15,40)
col_signs=rep(">=",3)
col_rhs=c(20,15,30)
lp_solution=lp.transport(cm,"min",row_signs,row_rhs,col_signs,col_rhs)
print("optimal transportation matrix")
print(lp_solution$solution)
print(paste("total cost:",lp_solution$objval))

#Transportation Problem 2 

library(lpSolve)
cm=matrix(c(11,20,7,8,
            21,16,20,12,
            8,12,18,9),nrow=3,byrow=TRUE)
print("cost matrix")
print(cm)
row_signs=rep("<=",3)
row_rhs=c(50,40,70)
col_signs=rep(">=",4)
col_rhs=c(30,25,35,40)
lp_solution=lp.transport(cm,"min",row_signs,row_rhs,col_signs,col_rhs)
print("optimal transportation matrix")
print(lp_solution$solution)
print(paste("total cost:",lp_solution$objval))

#Transportation problem 3

library(lpSolve)
cm=matrix(0,nrow=3,ncol=4)
cm[1,1]=14
cm[1,2]=56
cm[1,3]=48
cm[1,4]=27
cm[2,1]=82
cm[2,2]=35
cm[2,3]=21
cm[2,4]=81
cm[3,1]=99
cm[3,2]=31
cm[3,3]=71
cm[3,4]=63
print("cost matrix")
print(cm)
row_signs=rep("<=",3)
row_rhs=c(70,47,93)
col_signs=rep(">=",4)
col_rhs=c(70,35,45,60)
lp_solution=lp.transport(cm,"min",row_signs,row_rhs,col_signs,col_rhs)
print("optimal transportation matrix")
print(lp_solution$solution)
print(paste("total cost:",lp_solution$objval))