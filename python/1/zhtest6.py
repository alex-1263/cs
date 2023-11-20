#任务：编写程序实现一个银行账户管理系统支持开户、销户、计算所有账户的利息以及获取账户操作接口。每个账户支持依据账号进行存取款、查询储蓄额等操作。
#定义类
class acount:
    def __init__(self,acount_number,acount_name,acount_money,account_password):
        self.acount_number=acount_number
        self.acount_name=acount_name
        self.acount_money=acount_money
        self.account_password=account_password
    def save(self,money):
        self.acount_money+=money
    def get(self,money):
        self.acount_money-=money
    def show(self):
        print(self.acount_number,self.acount_name,self.acount_money)
    
class bank:
    def __init__(self):
        self.acounts=[]
    def add(self,acount):
        self.acounts.append(acount)
    def remove(self,acount):
        self.acounts.remove(acount)
    def show(self):
        for i in self.acounts:
            i.show()
    def get_all(self):
        sum=0
        for i in self.acounts:
            sum+=i.acount_money
        return sum
def main():
    #初始化银行实列
    bank1=bank()
    #初始化账户实列
    acount1=acount(1001,"张三",1000,"123456")
    acount2=acount(1002,"李四",2000,"123456")
    #从文件中读取账户信息,通过银行的添加账户能力初始化账户信息
    bank1.add(acount1)
    bank1.add(acount2)
    #显示所有账户信息
    bank1.show()
    while True:
        #输出菜单
        print("1.开户")
        print("2.销户")
        print("3.存款")
        print("4.取款")
        print("5.查询")
        print("6.计算账户的利息")
        print("7.退出")
        select_num=input("请输入你的选择:")
        if select_num=="1": #开户
            flag=0
            acount_number=int(input("请输入账号:"))
            for i in bank1.acounts:
                if i.acount_number==acount_number:
                    print("账号已存在")
                    flag=1
                    break
            if flag==1:
                continue
            acount_name=input("请输入姓名:")
            acount_money=int(input("请输入存款金额:"))
            account_password=input("请输入密码:")
            acount3=acount(acount_number,acount_name,acount_money,account_password)
            bank1.add(acount3)
        elif select_num=="2": #销户
            acount_number=int(input("请输入账号:"))
            account_password=input("请输入密码:")
            for i in bank1.acounts:
                if i.acount_number==acount_number and i.account_password==account_password:
                    bank1.remove(i)
                    break
            else:
                print("账号或密码错误")
        elif select_num=="3": #存款
            acount_number=int(input("请输入账号:"))
            account_password=input("请输入密码:")
            money=int(input("请输入存款金额:"))
            for i in bank1.acounts:
                if i.acount_number==acount_number and i.account_password==account_password:
                    i.save(money)
                    break
            else:
                print("账号或密码错误")
        elif select_num=="4": #取款
            acount_number=int(input("请输入账号:"))
            account_password=input("请输入密码:")
            money=int(input("请输入取款金额:"))
            for i in bank1.acounts:
                if i.acount_number==acount_number and i.account_password==account_password:
                    i.get(money)
                    break
            else:
                print("账号或密码错误")
        elif select_num=="5": #查询
            acount_number=int(input("请输入账号:"))
            account_password=input("请输入密码:")
            for i in bank1.acounts:
                if i.acount_number==acount_number and i.account_password==account_password:
                    i.show()
                    break
            else:
                print("账号或密码错误")
        elif select_num=="6": #计算查询账户的利息
            acount_number=int(input("请输入账号:"))
            account_password=input("请输入密码:")
            for i in bank1.acounts:
                if i.acount_number==acount_number and i.account_password==account_password:
                    print("账户的利息为:",i.acount_money*0.1)
                    break
            else:
                print("账号或密码错误")
        elif select_num=="7": #退出
            break
        else:
            print("输入错误,请重新输入")
main()
