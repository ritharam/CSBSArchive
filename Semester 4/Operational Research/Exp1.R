cons.1<- function(x) (10+x)/3
cons.2<- function(x) (6-x)
cons.3<- function(x) (x-2)
cons.4<- function(x) 0
cons.5<- function(x) 0

library(ggplot2)

p<- ggplot(data = data.frame(x=0), aes(x=x)) +
  geom_vline(xintercept = 0) +
  geom_hline(yintercept = 0) +
  stat_function(color = "red", fun = cons.1) +
  stat_function(color = "blue", fun = cons.2) +
  stat_function(color = "green", fun = cons.3) +
  scale_x_continuous(breaks = seq(0, 10, 1), lim = c(0, 10)) +
  scale_y_continuous(breaks = seq(0, 10, 1), lim = c(0,10)) +
  labs(title ="optimization problem", subtitle = "graphical method of lpp problem", x ="x1", y = "x2") +
  theme_bw()

print(p)

#define the feasible region polygon
feasible_region = data.frame(x = c(0,2,4,2,0), y = c(0,0,2,4,3.3))

#add feasible region to current plot
p<- p + geom_polygon(data = feasible_region, mapping = aes(x= x, y=y), fill = "#dddddd") + 
  geom_point(data = feasible_region, aes(x=x, y=y), color = "black")
print(p)

library(lpSolve)

f.obj<- c(-1,2)
f.con<-matrix(c(-1,3,
                1,1,
                1,-1), nrow = 3, byrow = TRUE)
f.dir<-c("<=", "<=","<=")
f.rhs<-c(10,6,2)
lp_result<-lp("min", f.obj, f.con, f.dir, f.rhs)
solution<- lp_result$solution
p<-p+ geom_point(aes(x=solution[1], y=solution[2], color ="red", size = 4))
print(p)