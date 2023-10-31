import math

n=input("请输入n的值:")
if n>999:
    n=1000
for i in range(100,n):
    i_str=str(i)
    a=int(i_str(0))
    b=int(i_str(1))
    c=int(i_str(2))
    sum=pow(a,3)+pow(b,3)+pow(c,3)
    if sum == i:
        print("有水仙花数")
        break
else:
    print("没有水仙花数")