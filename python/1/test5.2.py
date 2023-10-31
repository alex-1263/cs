import re
text=open("D:/Document/cs/python/1/data.txt")
list1=text.readlines()
list2=list()
print(list1)
for i in list1:
    i=re.findall(r"\d+\.?\d*",i)
    list2.append(i)
print(list2)



