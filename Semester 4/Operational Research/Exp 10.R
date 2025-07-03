#.Replacement model

ini_cost <- 6000
scrap <- c(3000, 1500, 750, 375, 200, 200)
main_cost <- c(1000, 1200, 1400, 1800, 2300, 2800)
cat(cumsum(main_cost))
total <- ini_cost - scrap + cumsum(main_cost)
cat(total)
avg_cost <- total / (1:length(total))
cat(avg_cost)
optimal_year <- which.min(avg_cost)

cat("Year: ", optimal_year, "\n")
cat("Average cost: Rs. ", avg_cost[optimal_year], "\n")

-----------------------------------------------------------
  
#Inventory Model
  
annual_demand=200
inventory_cost=1
holding_cost=25
EOQ=sqrt((2*annual_demand*inventory_cost)/holding_cost)
time_between_orders=EOQ/annual_demand
orders_per_year=annual_demand/EOQ
c_min=sqrt(2*inventory_cost*holding_cost*annual_demand)
total_cost=(annual_demand)+c_min

cat("economic order ",round(EOQ),"\n")
cat("time b/w two consecutive orders ",round(time_between_orders,2),"years\n")
cat("minimum average yearly cost Rs.",round(c_min),"\n")
cat("no of orders per year ",round(orders_per_year,2),"\n")
cat("optimal total cost: ",round(total_cost))