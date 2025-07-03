# choco = [4, -2, 2]
# kids = [3, 4, 5]

# choco.sort()
# kids.sort()

# mins = []

# for i in range(0,3):
#     x = abs(choco[i] - kids[i])
#     mins.append(x)

# print(max(mins))

#problem 2. Mice hole problem 
k=[]
c=[]
n=int(input("enter how many kids:"))
print("enter the positions of kids:")
for i in range(n):
    a=int(input())
    k.append(a)
print("enter the position of chocolate shelf:")
for i in range(n):
    b=int(input())
    c.append(b)
k.sort()
c.sort()
diff=[]
for i in range(n):
    d=abs(k[i]-c[i])
    diff.append(d)

for i in range(n):
    print("kid ",i+1," has moved ",diff[i]," steps to reach chocolate at position ",c[i]," from ",k[i])
print("the maximum time taken by those kids to reach their shelves is:",max(diff))