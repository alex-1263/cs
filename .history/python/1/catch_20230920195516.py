import random
from random import randint

n=int(10) #洞口数量
chance=int(10) #天数
hl=0           #狐狸位置
w=0             #要抓的洞口编号
def csh():                                                  #初始化
    global n,chance,hl,w
    print("洞口的数量是%d,天数为%d" %(n,chance))
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
                chance=int(input("请输入天数：  "))
                assert chance>0
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
                chance=int(input("请输入天数：  "))
                assert chance>0
                break
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0的整数")


    print("现在的洞口数为%d,天数为%d"%(n,chance))
    hl=randint(1,n)
def catch():                                        #抓狐狸
        global n,chance,hl,w
        while True:
            try:
                print("狐狸现在的位置为%d"%hl)
                w=int(input("请输入你要抓的洞口编号：  "))
                assert 0<w<=n
                break 
            except ValueError:
                print("请输入整数")
            except AssertionError:
                print("请输入大于0并小于%d的数" %n)
def jump():                                        #狐狸更改位置
    global n,chance,hl,w
    if(hl==1):
        hl=2
    elif(hl==n):
        hl=n-1
    else:
        x=random.choice([1,-1])
        hl+=x
    chance-=1


#测试代码





#实际代码



        



