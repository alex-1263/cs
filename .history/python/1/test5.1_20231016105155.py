f=open("D:/Document/cs/python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
list2=list()
print(list1)
for i in range(len(list1)):
    list1[i]=list1[i]
    list2.append(list1[i]+'#')
    print(list1[i],end='')

f.close()