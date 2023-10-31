dict1={"A":"山羊","B":"山羊","C":"车"}
first=str(input("请输入第一个选择的门:"))
if dict1[first]=="车":
    key1=[k for k ,v in dict1.items() if v!=dict1[first] ][0]
    print(key1)
else:
    key1=[k for k,v in dict1.items() if v==dict1[first] and k!=first][0]
    print(key1)