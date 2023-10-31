import random
from random import randint

n=int(10) #洞口数量
chance=int(10) #机会数
print("洞口的数量是%d,机会数为%d" %(n,chance))
c = input("如果需要修改洞口数请输入A,需要修改机会数请输入B,都需要修改请输入C,不需修改请输入其他:  ")
if(c=='A'):
    while True:                                     #输入洞口数并判断是否合法
        try:
            n=int(input("请输入洞口数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")


elif(c=='B'):                                       #输入机会数并判断是否合法
    while True:
        try:
            chance=int(input("请输入机会数：  "))
            assert n>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数")


elif(c=='C'):                                       #输入洞口数和机会数并判断是否合法
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


print("现在的洞口数为%d,机会数为%d"%(n,chance))       #告知用户现在的洞口数和机会数

hl=randint(1,n)                                     #狐狸的位置为1-n的随机整数

while True:                                         #循环输入洞口编号并判断是否抓到
    while True:                                     #输入洞口编号并判断是否合法
        try:
            w=int(input("请输入您要抓的洞口编号：  "))
            assert n>w>0
            break
        except ValueError:
            print("请输入整数")
        except AssertionError:
            print("请输入大于0的整数,小于n的整数")
    if(w==hl):                                      #判断是否抓到狐狸
        print("您抓到了狐狸，它在编号为%d的洞口"%w)
        break
    else:                                           #没抓到狐狸时
        chance-=1
        if(chance==0):                              #剩余机会为0的情况
            print("您的机会用完了，游戏结束")
            break
        print("您没抓住狐狸,您还有%d次机会"%chance)   #剩余机会不为0的情况
        if(hl==1):                                  #狐狸在两端的洞口如何移动
            hl=2
        elif(hl==n):
            hl=n-1
        else:                                       #狐狸在中间的洞口如何移动
            x=random.choice([-1,1])                        #设x为1-2的随机整数，为1则洞口编号-1，为2则洞口编号+1
            hl+=x
    print("狐狸的位置现在为%d"%hl)                    #测试中显示狐狸位置，实际游戏中不显示

            



