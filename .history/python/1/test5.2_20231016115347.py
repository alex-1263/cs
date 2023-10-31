text=open("D:/Document/cs/python/1/data.txt")
list1=text.readlines()
list2=list()

for i in range(len(list1)):
    for j in range(len(list1[i])):
        if(j[i]>='0' and j[i]<='9'):
            list2