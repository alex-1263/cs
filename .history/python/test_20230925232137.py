s=["ling","yi","er","san","si","wu","liu","qi","ba","jiu"]
x=str(input())

for i in range(len(x)):
    if(x[i]=='-'):
        print("fu")
    else :
        format(s[int(x[i])])
    