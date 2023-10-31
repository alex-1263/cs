import math

n=int(input("请输入n的值:"))
if n > 999:
    nl=1000
else:
    nl=n
for i in range(100,nl):
    i_str=str(i)
    a=int(i_str[0])
    b=int(i_str[1])
    c=int(i_str[2])
    sum=pow(a,3)+pow(b,3)+pow(c,3)
    if sum == i:
        print("%d以内有水仙花数，第一个水仙花数为%d"%(n,i))
        break
else:
    if(nl<100):
        print("请输入大于100的值")
    print("没有水仙花数")