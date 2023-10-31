import re
text=open("D:/Document/cs/python/1/data.txt")
list1=text.readlines()
str2=""
list1=list()
n=0
for i in list1:
    i=re.sub('\D','',i)
print(list1)




)