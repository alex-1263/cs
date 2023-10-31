
list1=input("请输入一个列表：")
list1=eval(list1)
print(list1)
list3=[]


list2=[list1[x] for x in range(len(list1)) if list1[x]>0]
print(list2)

for i in range(len(list1)):
    if(list1[i]!='-'):
        list3.append(list1[i])
    
print(list3)       