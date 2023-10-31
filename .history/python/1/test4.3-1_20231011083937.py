dict1={"A":"山羊","B":"山羊","C":"车"}
first=str(input("请输入第一个选择的门:"))
print(dict1[first])
if(dict1[first]=="山羊"):
    print("hello")
key=[k for k , v in dict1.items() if v==dict1[first] and k!=first]
print(key)