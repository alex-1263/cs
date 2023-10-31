import random
dict1={"A":"","B":"","C":""}
car=random.choice(["A","B","C"])
for i in dict1.keys():
    if(car==i):
        dict1[car]="车"
    else:
        dict1[i]="山羊"

print(dict1)
while True:
    try:
        first=str(input("请输入第一个选择的门:"))
        assert first>="A" and first<="B"
        break
    except ValueError:
        print("请输入字符")
    except AssertionError:
        print("请输入A-C的字符")

if dict1[first]=="车":
    key1=[k for k ,v in dict1.items() if v!=dict1[first] ][int(random.choice([0,1]))]
    print(key1)
else:
    key1=[k for k,v in dict1.items() if v==dict1[first] and k!=first][0]

print("门%c后面是山羊"%key1)

while True:
    try:
        second=str(input("请输入第二个选择的门："))
        assert second>="A" and second<="B"
        break
    except ValueError:
        print("请输入字符")
    except AssertionError:
        print("请输入A-C的字符")
if dict1[second]=="车":
    print("游戏胜利")
else:
    print("游戏结束")