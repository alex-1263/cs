text=open("D:/Document/cs/python/1/data.txt")
list1=text.readlines()
list2=list()

for i in range(len(list1)):
    for j in range(len(list1[i])):
        if(type(j)==int):
            list2[i]=list2[i]+str(j[i])