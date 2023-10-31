username="alex1263"
password="123456"
n=3
for i in range(3):
    a=str(input("请输入用户名："))
    b=str(input("请输入密码："))
    if a==username and b==password:
        print("登录成功！")
        break
    else:
        print("输入错误你还有%d次机会"% n-i)
else:
    print("您已错误三次，请再回忆")
