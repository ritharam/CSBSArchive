def get_list_from_input(prompt):
    return list(map(int, input(prompt).split()))

list1 = get_list_from_input("Enter the first list (space-separated values): ")
list2 = get_list_from_input("Enter the second list (space-separated values): ")

cross_over_point = int(input("Enter the cross_over_point: "))

new_list1 = list1[:cross_over_point] + list2[cross_over_point:]
new_list2 = list2[:cross_over_point] + list1[cross_over_point:]

print("New list 1:", new_list1)
print("New list 2:", new_list2)

check = input("Do you want the mutation? (y/n) :")
if(check == 'y'):
    which_child = int(input("for which child you want mutaion (1,2 or both) : "))
   
    if which_child == 1:
        pos = int(input("At what position you want to mutate? :"))
        val = int(input("Enter the value you want to mutate : "))
        new_list1[pos] = val
    elif which_child == 2:
         pos = int(input("At what position you want to mutate? :"))
         val = int(input("Enter the value you want to mutate : "))
         new_list2[pos] = val
    else:
        print("For child 1")
        pos = int(input("At what position you want to mutate? :"))
        val = int(input("Enter the value you want to mutate : "))
        new_list1[pos] = val
        print("For child 2")
        pos = int(input("At what position you want to mutate? :"))
        val = int(input("Enter the value you want to mutate : "))
        new_list2[pos] = val
    print("After mutaion ")
    print("New list 1:", new_list1)
    print("New list 2:", new_list2)