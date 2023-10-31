while True:
    try:
        n=int(input("请输入评委人数"))
        assert 2<n
        break
    except AssertionError:
        print("请输入大于2的评委人数")
ans=0
max=-1
min=999
for i in range(n):
    while True:
        try:
            pingfeng=int(input("请输入评分："))
            assert 0<pingfeng<100
            ans=ans+pingfeng
            if(max<pingfeng):
                max=pingfeng
            if(min>pingfeng):
                min=pingfeng
            break
        except AssertionError:
            print("请输入大于0小于100的评分")

ans=ans-max-min
x=float(ans)/(n-2)
print(x)
