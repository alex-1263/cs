import random
from random import randint

n=int(10) #洞口数量
chance=int(10) #机会数
print("洞口的数量是%d,机会数为%d" %(n,chance))
c = input("如果需要修改洞口数请输入A,需要修改洞口数请输入B,都需要修改请输入C,不需修改请输入其他:  ")
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

while True:
    while True:
        try:
            w=int(input("请输入您要抓的洞口编号：  "))
            assert n>w>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数,小于n的整数")
    if(w==hl):
        print("您抓到了狐狸，它在编号为%d的洞口"%w)
        break
    else:
        chance-=1
        if(chance==0):
            print("您的机会用完了，游戏结束")
            break
        print("您没抓住狐狸,您还有%d次机会"%chance)
        if(hl==1):
            hl=2
        elif(hl==n):
            hl=n-1
        else:
            x=randint(1,2)
            if(x==1):
                hl+=1
            else:
                hl-=1
    

            



