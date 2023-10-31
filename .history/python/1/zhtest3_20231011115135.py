import random
import time
n=int(input("请输入进程数"))
list1=list()
list2=list()
for i in range(n):
    list1.append(int(input("请输入该进程运行需要的时间：")))
    t=random.random()
    time.sleep(t)
    list2[i]=t
print(list1)
print(list2)
