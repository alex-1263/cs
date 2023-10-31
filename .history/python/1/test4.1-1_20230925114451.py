list1 =[88,5,8,6,1,23,1,15,61,31,6];
list1.sort(reverse=True)
list2 =[];
print(list1)
for  i in range(len(list1)):
    if(i==0):
        list2.append(list[i])
    elif(list2[len(list2)-1]<list[i]):
        list2.append(list1[i])
print(list1)