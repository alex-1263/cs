f=open("D:/Document/cs/python/1/demo.py","+r",encoding="utf8")
w=open("D:/Document//cs//python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
max_lenth=0
for i in list1:
    max_lenth=max(max_lenth,len(i))

list2=list()
print(list1)
for i in list1:
    i=i.rstrip('\n')
    i=i.ljust(max_lenth,' ')
    i=i+'#'
    print(i)
    list2.append(i)

f.close()