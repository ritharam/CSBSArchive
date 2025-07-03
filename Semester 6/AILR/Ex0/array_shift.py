# #Left & Right Shift
# def shift(n,arr,di,x):
#     arr2=[0 for i in range(n)]
#     if di == 'R':
#         for i in range(n-x):
#             arr2[x+i] = arr[i]
#         i = 0
#         for j in range(n-x,n):
#             arr2[i] = arr[j]
#             i+=1
#     else:
#         for i in range(n-x):
#             arr2[i] = arr[x+i]
#         i = 0
#         for j in range(n-x,n):
#             arr2[j] = arr[i]
#             i+=1
#     return arr2        
# n = int(input("Enter the Number of Elements in List :"))
# arr = [input('Enter Element {} :'.format(i+1)) for i in range(n)]   
# arr = shift(n,arr,input("Left or Right Shift(L/R) :"),int(input("Enter Number of Digits to Shift :")))
# print("Shifted Array :",arr)

def shiftright(lst,r):
  r = r % len(lst)
  lst.extend(lst[:r])
  del lst[:r]
  print(lst)

def shiftleft(lst,r):
  r = r % len(lst)
  lst.extend(lst[:r-1])
  del lst[:r-1]
  print(lst)

n = int(input("Enter the number of list elements : "))
lst = [int(input()) for i in range(n)]
lst = [1,2,3,4,5]
print(lst)

print("Choose Shift right(1) or Shift left(2) : ")
ch = int(input())

r = int(input("Number of shifts : "))

if ch == 1:
  shiftright(lst,r)
elif ch == 2:
  shiftleft(lst,r)
