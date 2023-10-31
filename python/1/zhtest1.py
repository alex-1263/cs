import math
from decimal import Decimal, ROUND_HALF_UP
cash=float(input("请输入收入："))
people=int(input("请输入你的抚养人数："))
ans=cash*0.2-5000-people*1000
number=str(ans)
result=Decimal(number).quantize(Decimal('0.00'),ROUND_HALF_UP)
print("您的收入税是%s" %result)
