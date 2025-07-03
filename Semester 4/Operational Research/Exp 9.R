#Queueing Problem

lamda <- 10 / 60  #Arival time 
mu <- 1 / 3       #Service time
#Calculate rho
traffic_intensity <- function(lamda, mu) {
  rho <- lamda / mu 
  return(rho)
}
#Calculate average customers waiting in the queue (Lq)
avg_num_customers_queue<-function(lamda,mu)
{
  rho<-traffic_intensity(lamda,mu)
  Lq<-(rho^2/(1-rho))
  return(Lq)
}
# Additional measures
rho<-traffic_intensity(lamda,mu)
Lq<-avg_num_customers_queue(lamda,mu)
Ls<-Lq+lamda/mu
Ws<-Ls/lamda
Wq<-Lq/lamda
cat("traffic intensiy(rho):",round(rho,4),"\n")
cat("Average no of customers waiting in a queue (Lq):",round(Lq,4),"\n")
cat("Average no of customers  in a system (Ls):",round(Ls,4),"\n")
cat("Average time a customer spends in system  (Ws):",round(Ws,4),"minutes\n")
cat("Average time a customers spends waiting in a queue (Wq):",round(Wq,4),"minutes\n")

---------------------------------------------------------------------------------------------

lamda<-1/12
mu<-1/4
traffic_intensity<-function(lamda,mu){
  rho<-lamda/mu
  return(rho)
}
avg_num_customers_queue<-function(lamda,mu)
{
  rho<-traffic_intensity(lamda,mu)
  Lq<-(rho^2/(1-rho))
  return(Lq)
}
rho<-traffic_intensity(lamda,mu)
Lq<-avg_num_customers_queue(lamda,mu)
Ls<-Lq+lamda/mu
Ws<-Ls/lamda
Wq<-Lq/lamda
cat("traffic intensiy(rho):",round(rho,4),"\n")
cat("Average no of customers waiting in a queue (Lq):",round(Lq,4),"\n")
cat("Average no of customers  in a system (Ls):",round(Ls,4),"\n")
cat("Average time a customer spends in system  (Ws):",round(Ws,4),"\n")
cat("Average time a  customers spends waiting in a queue (Wq):",round(Wq,4),"\n")  
    
---------------------------------------------------------------------------------------------

lambda <- 20
mu <- 11
servers <- 2

traffic_intensity <- function(lambda, mu, servers) {
  rho <- lambda / (servers * mu)
  return(rho)
}

# Function to calculate the probability of system being idle (P0)
prob_idle_state <- function(lambda, mu, servers) {
  rho <- traffic_intensity(lambda, mu, servers)
  p0_sum <- 0
  
  for (n in 0:(servers - 1)) {
    p0_sum <- p0_sum + (servers * rho)^n / factorial(n)
  }
  
  second_term <- (servers * rho)^servers / (factorial(servers) * (1 - rho))
  p0 <- 1 / (p0_sum + second_term)
  return(p0)
}

# Calculate probability of system being idle (P0)
P0 <- prob_idle_state(lambda, mu, servers)

# Function to calculate the probability of server being busy (Ps)
prob_server_busy <- function(lambda, mu, servers) {
  p0 <- prob_idle_state(lambda, mu, servers)
  Ps <- ((lambda / mu)^servers / factorial(servers)) * p0
  return(Ps)
}

# Function to calculate the average number of customers waiting in the queue (L0)
avg_num_customers_queue <- function(lambda, mu, servers) {
  rho <- traffic_intensity(lambda, mu, servers)
  P0 <- prob_idle_state(lambda, mu, servers)
  Ps <- ((lambda / mu)^servers / factorial(servers)) * P0
  Lq <- Ps * (rho / (1 - rho)^2)
  return(Lq)
}

# Calculate additional measures
rho <- traffic_intensity(lambda, mu, servers)
Ps <- prob_server_busy(lambda, mu, servers)
Lq <- avg_num_customers_queue(lambda, mu, servers)
Ls <- Lq + lambda / mu
Ws <- Ls / lambda
Wq <- Lq / lambda

cat("Traffic intensity (rho): ", round(rho, 4), "\n")
cat("Probability of system being idle (P0): ", round(P0, 4), "\n")
cat("Probability of a server being busy (Ps): ", round(Ps, 4), "\n")
cat("Average number of customers waiting in the queue (Lq): ", round(Lq, 4), "\n")
cat("Average number of customers in the system (Ls): ", round(Ls, 4), "\n")
cat("Average time a customer spends in the system (Ws): ", round(Ws, 4), " hour\n")
cat("Average time a customer spends waiting in the system (Wq): ", round(Wq, 4), " hour\n")

