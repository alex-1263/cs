import random
from random import randint

n=int(10) #洞口数量
chance=int(10) #天数
def csh(dk,t):
    print("洞口的数量是%d,天数为%d" %(dk,t))
    c = input("如果需要修改洞口数请输入A,需要修改洞口数请输入B,都需要修改请输入,不需修改请输入其他:  ")
    if(c=='A'):
        while True:
            try:
                dk=int(input("请输入洞口数：  "))
                assert dk>0
                break
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0的整数")


    elif(c=='B'):
        while True:
            try:
                t=int(input("请输入天数：  "))
                assert t>0
                break
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0的整数")


    elif(c=='C'):
        while True:
            try:
                dk=int(input("请输入洞口数：  "))
                assert dk>0
                break
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0的整数")
        while True:
            try:
                t=int(input("请输入天数：  "))
                assert t>0
                break
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0的整数")


    print("现在的洞口数为%d,天数为%d"%(dk,t))
    hl=randint(1,n)
def catch():
        while True:
            try:
                w=int(input("请输入你要抓的洞口编号：  "))
                assert 0<w<=n
                break 
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0并小于%d的数" %n)
def jump():
    if(hl==1):
        hl=2
    elif(hl==n):
        hl=n-1
    else:
        hl+=random.choice(-1,1)
    chance-=1

csh(dk,t)
while True:
    catch()
    if(hl==w):
        print("你抓住了狐狸，它在编号为%d的洞口" %w)
        break
    jump()
    if(chance==0):
        print("你的天数已用完，游戏结束")
        break


        



