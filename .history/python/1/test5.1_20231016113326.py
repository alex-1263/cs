f=open("D:/Document/cs/python/1/demo.py","+r",encoding="utf8")
 
list1=f.readlines()

list2=list()
print(list1)
for i in list1:
    i.replace('\n',' ')
    print(i,end='')
print(list1)
f.close()