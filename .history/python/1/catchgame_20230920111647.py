import random
from random import randint

n=int(10) #洞口数量
chance=int(10) #机会数
print("洞口的数量是%d,机会数为%d" %(n,chance))
c = input("如果需要修改洞口数请输入A,需要修改洞口数请输入B,都需要修改请输入,不需修改请输入其他:  ")
if(c=='A'):
    while True:
        try:
            n=int(input("请输入洞口数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")


elif(c=='B'):
    while True:
        try:
            chance=int(input("请输入机会数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")


elif(c=='C'):
    while True:
        try:
            n=int(input("请输入洞口数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")
    while True:
        try:
            chance=int(input("请输入机会数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")


print("现在的洞口数为%d,机会数为%d"%(n,chance))

hl=randint(1,n)
