min=99999999999999
n=int(input("请输入n:"))
i=0
while i<n:
    x1=float(input("请输入值："))
    if x1<min:
        min=x1
    i+=1
print(x1)

min=99999999999999
n=int(input("请输入n:"))
i=0
for i in range(1,n,1):
    x1=float(input("请输入值："))
    if x1<min:
        min=x1
    i+=1

