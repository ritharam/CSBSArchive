#define objective function 
obj_fn=c(1,-3,2)

#define constraints
f1cons = c(3,-1,3)
f2cons = c(-2,4,0)
f3cons = c(-4,3,8)

#define rhs values of constraints
c1 = 7
c2 = 12
c3 = 10

library(boot)
#solve the linear programming problem using the simplex method
simplex(a=obj_fn,A1=rbind(f1cons,f2cons,f3cons),b1=c(c1,c2,c3),maxi=F)