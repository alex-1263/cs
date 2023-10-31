import math
from decimal import Decimal, ROUND_HALF_UP
cash=float(input("请输入收入："))
people=int(input("请输入你的抚养人数："))
ans=(cash-5000-people*1000)*0.2
number=str(ans)
result=number.quantize(Decimal('0.00'),ROUND_HALF_UP)
if ans<0 :
    print("您不需要交收入税")
else :
    print("您的收入税是%.2f" %ans)
