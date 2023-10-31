import re
text=open("D:/Document/cs/python/1/data.txt")
list1=text.readlines()
str2=""
list2=list()
n=0
for i in list1:
    i=re.sub('\D','',i)
    list2.append(i)
print(list2)




