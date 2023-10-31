f=open("D:/Document/cs/python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
list2=list()
print(list1)
for i in list1:
    print(i,end='')

f.close()