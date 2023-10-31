while True:
    try:
        n=int(input("请输入评委人数"))
        assert 2<n
        break
    except AssertionError:
        print("请输入大于2的评委人数")
ans=0                        #分数总和       
max=-1                       #记录最高分初始化
min=999                      #记录最低分初始化
for i in range(n):           #循环次数为评委人数n
    while True:              #输入评分
        try:
            pingfeng=int(input("请输入评分："))
            assert 0<pingfeng<100   #判断分数是否合法
            ans=ans+pingfeng        #记录分数总和
            if(max<pingfeng):       #更新最高分和最低分
                max=pingfeng
            if(min>pingfeng):
                min=pingfeng
            break
        except AssertionError:
            print("请输入大于0小于100的评分")

ans=ans-max-min                     #计算平均分
x=float(ans)/(n-2)
print(x)
