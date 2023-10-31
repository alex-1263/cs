import random
dict1={"A":"山羊","B":"山羊","C":"车"}

first=str(input("请输入第一个选择的门:"))
if dict1[first]=="车":
    key1=[k for k ,v in dict1.items() if v!=dict1[first] ][int(random.choice([0,1]))]
else:
    key1=[k for k,v in dict1.items() if v==dict1[first] and k!=first][0]

print("门%c后面是羊"%key1)
second=str(input("请输入第二个选择的门："))
if dict1[second]=="车":
    print("游戏胜利")
else:
    print("游戏结束")