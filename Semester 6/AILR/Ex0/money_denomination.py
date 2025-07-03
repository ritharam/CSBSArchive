rup = int(input("Enter the amount :"))
den = [500,200,100,50,20,10,5,2,1]
for i in den:
  print(rup//i,"notes of",i)
  rup = rup%i