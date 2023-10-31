list1 =[10,9,-1,-3,-6]
list2=[list1[x] for x in range(len(list1)) if list1[x]>0]
print(list2)