import math
cash=float(input("请输入收入："))
people=int(input("请输入你的被抚养人数："))
ans=cash*0.2-5000-people*1000
if ans<0:
    print("您不需要交收入税")
else：
    print("您的收入税是%.2f" %ans)
