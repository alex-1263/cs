f=open("D:/Document/cs/python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
list2=list()
print(list1)
print(list1[0][0])
for i in range(len(list1)):
    print(list1[i],end='')

f.close()