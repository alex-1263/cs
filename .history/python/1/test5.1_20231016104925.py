f=open("D:/Document/cs/python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
print(list1)
for i in range(len(list1)):
    list1[i]=list1[i][len(list1[i])-1]
    print(list1[i])

f.close()