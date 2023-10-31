username="alex1263"
password="123456"
n=3
for i in range(3):
    a=(input("请输入用户名："))
    b=(input("请输入密码："))
    if a==username & b==password:
        print("登录成功！")
        break
else:
    print("您已错误三次，请再回忆")
