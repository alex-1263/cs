dict1={"A":"山羊","B":"山羊","C":"车"}
first=str(input("请输入第一个选择的门:"))
print(dict1[first])
print(dict1.get("车"))
if(dict1[first]=="山羊"):
    print("hello")