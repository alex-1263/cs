n=int(input("请输入list的长度"))
list1=[]
list3=[]
for i in range(n):
    list1.append(int(input()))

list2=[list1[x] for x in range(len(list1)) if list1[x]>0]
print(list2)

for i in range(n):
    if(list1[i]>=0):
        list3.append(list1[i])
    
print(list3)       