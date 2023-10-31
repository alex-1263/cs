import random
from random import randint

n=10 #洞口数量
chance=10 #机会数
print("洞口的数量是%d,机会数为%d" %(n,chance))
c = input("如果需要修改洞口数请输入A,需要修改洞口数请输入B,都需要修改请输入,不需修改请输入其他:  ")
if(c=='A'):
    while True:
        try:
            n=input()
            assert n>0
            break
        except AssertionError:
            print("请输入大于0的数")
        except TypeError:
            print("请输入整数")

elif(c=='B'):
    chance=int(input())
elif(c=='C'):
    n=int(input())
    chance=int(input())
print("现在的洞口数为%d,机会数为%d"%(n,chance))

hl=randint(1,n)
