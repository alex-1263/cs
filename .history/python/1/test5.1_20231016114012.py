f=open("D:/Document/cs/python/1/demo.py","+r",encoding="utf8")
 
list1=f.readlines()
max_lenth=0
for i in list1:
    max_lenth=max(max_lenth,len(i))

list2=list()
print(list1)
for i in list1:
    i=i.rstrip('\n')
    i.rjust(max_lenth,' ')
    print(i)
    list2.append(i)
print(list2)
f.close()