import random
import time
n=int(input("请输入进程数"))
list1=list()
list2=list()
for i in range(n):
    list1[i]=int(input("请输入该进程运行需要的时间："))
    t=random(0,1)
    time.sleep(t)
