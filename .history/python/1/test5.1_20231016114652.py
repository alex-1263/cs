f=open("D:/Document/cs/python/1/demo.py","+r",encoding="utf8")
w=open("D:/Document//cs//python/1/try.py","+r",encoding="utf8")
list1=f.readlines()
max_lenth=0
for i in list1:
    max_lenth=max(max_lenth,len(i))

list2=list()
print(list1)
for i in range(len(list1)):
    list1[i]=list1[i].rstrip('\n')
    list1[i]=list1[i].ljust(max_lenth,' ')
    list1[i]=list1[i]+'#'+'%d, i'+'\n'
    list2.append(list1[i])
w.writelines(list2)
w.close()
f.close()