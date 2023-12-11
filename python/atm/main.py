User
# 任务：编写程序实现一个银行账户管理系统支持开户、销户、计算所有账户的利息以及获取账户操作接口。每个账户支持依据账号进行存取款、查询储蓄额等操作。
# 定义类
import json
class account:  # 账户类
    def __init__(self, account_number, account_name, account_money, account_password):
        self.account_number = account_number
        self.account_name = account_name
        self.account_money = account_money
        self.account_password = account_password


# 定义用户账户类
class user_account:  #
    def __init__(self, user_name, user_number, user_password):
        self.user_name = user_name
        self.user_number = user_number
        self.user_password = user_password


# 定义用户类
class user:
    def __init__(self):
        self.user_accounts = []

    # 添加账户
    def add(self, user_account):
        self.user_accounts.append(user_account)

    # 删除账户
    def remove(self, user_account):
        self.user_accounts.remove(user_account)

    # 获取银行类的账户全部信息,除账户金额信息,加入用户类的账户列表
    def get_accounts(self, bank):
        # 清空用户类的账户列表
        self.user_accounts.clear()
        for i in bank.accounts:
            user_account1 = user_account(i.account_name, i.account_number, i.account_password)
            self.add(user_account1)

    # 获取银行类的最新账户信息,除账户金额信息,加入用户类的账户列表
    def get_accounts_new(self, bank):
        i = len(bank.accounts) - 1
        user_account1 = user_account(bank.accounts[i].account_name, bank.accounts[i].account_number,
                                     bank.accounts[i].account_password)
        self.add(user_account1)

    # 显示用户的账户信息
    def show(self):
        for i in self.user_accounts:
            print("账户名：", i.user_name)
            print("账号：", i.user_number)
            print("密码：", i.user_password)


# 定义银行类
class bank:
    def __init__(self):
        self.accounts = []

    # 存款
    def save(self, account_number, account_money):
        for i in self.accounts:
            if account_number == i.account_number:
                i.account_money += account_money
                return True
        return False

    # 取款
    def get(self, account_number, account_money):
        for i in self.accounts:
            if account_number == i.account_number:
                i.account_money -= account_money
                return True
        return False

    def save_to_file(self, filename='bank_data.json'):
        data = [{'account_number': acc.account_number,
                 'account_name': acc.account_name,
                 'account_money': acc.account_money,
                 'account_password': acc.account_password} for acc in self.accounts]

        with open(filename, 'w') as file:
            json.dump(data, file)

    def load_from_file(self, filename='bank_data.json'):
        try:
            with open(filename, 'r') as file:
                data = json.load(file)
                self.accounts = [account(**acc_data) for acc_data in data]
        except FileNotFoundError:
            print("文件不存在，将创建一个新文件。")

    # 查询
    def query(self, account_number):
        for i in self.accounts:
            if account_number == i.account_number:
                return i.account_money
        return False

    # 计算账户的利息
    def interest(self, account_number):
        for i in self.accounts:
            if account_number == i.account_number:
                interest = i.account_money * 0.05
                print("您的利息为：", interest)
                return True

    # 登录
    def login(self):
        account_number = int(input("请输入账号："))
        account_password = input("请输入密码：")
        for i in self.accounts:
            if account_number == i.account_number and account_password == i.account_password:
                number = i.account_number
                return number

        return False

    # 保持登录状态
    def login_status(self, account_number):
        while True:
            print("1.存款")
            print("2.取款")
            print("3.查询")
            print("4.计算账户的利息")
            print("5.注销")
            print("6.退出")
            choice = int(input("请输入你的选择："))
            if choice == 1:
                print("您选择的是存款")
                print("您的账户余额为：", self.query(account_number))
                account_money = int(input("请输入存款金额："))
                self.save(account_number, account_money)
                print("存款成功")
                print("您的账户余额为：", self.query(account_number))
            if choice == 2:
                print("您选择的是取款")
                print("您的账户余额为：", self.query(account_number))
                account_money = int(input("请输入取款金额："))
                self.get(account_number, account_money)
                print("取款成功")
                print("您的账户余额为：", self.query(account_number))
            if choice == 3:
                print("您选择的是查询")
                print("您的账户余额为：", self.query(account_number))
            if choice == 4:
                print("您选择的是计算账户的利息")
                self.interest(account_number)
            if choice == 5:
                print("您选择的是注销")
                self.delete(account_number)
                break
            if choice == 6:
                break


    # 开户
    def create(self):
        account_number = int(input("请输入账号："))
        if self.query(account_number):
            print("账号已存在")
            return False
        account_name = input("请输入姓名：")
        account_money = 0
        account_password = input("请输入密码：")
        account1 = account(account_number, account_name, account_money, account_password)
        self.add(account1)
        return True

    # 销户
    def delete(self, account_number):
        account_password = input("请输入密码确认：")
        for i in self.accounts:
            if account_number == i.account_number and account_password == i.account_password:
                self.remove(i)
                return True
        print("密码错误")
        return False

    # 添加账户
    def add(self, account):
        self.accounts.append(account)

    # 删除账户
    def remove(self, account):
        self.accounts.remove(account)

    # 显示所有账户信息
    def show(self):
        for i in self.accounts:
            print("账号：", i.account_number)
            print("姓名：", i.account_name)
            print("金额：", i.account_money)
            print("密码：", i.account_password)


def biaojiao(bank, user):
    if len(bank.accounts) != len(user.user_accounts):
        print("数据不一致,更新用户列表")
        return True

# 修改 main 函数，加入数据加载和保存
def main():
    bank1 = bank()
    # 初始化用户实列
    user1 = user()

    # 尝试加载账户信息
    bank1.load_from_file()

    while True:
        if biaojiao(bank1, user1):
            user1.get_accounts(bank1)

        print("1.登陆")
        print("2.开户")
        print("3.退出")
        choice = int(input("请输入你的选择："))
        if choice == 1:
            print("您选择的是登陆")
            account_number = bank1.login()
            if account_number:
                print("登陆成功")
                bank1.login_status(account_number)
            else:
                print("登陆失败,请确认账号密码")
        if choice == 2:
            print("您选择的是开户")
            if bank1.create():
                print("开户成功")
                user1.get_accounts_new(bank1)
            else:
                print("开户失败,有重复账户")
        if choice == 3:
            # 在退出前保存账户信息到文件
            bank1.save_to_file()
            break

if __name__ == "__main__":
    # 初始化银行实列
    bank1 = bank()
    # 初始化用户实列
    user1 = user()
    bank1.load_from_file()
    # 从银行类中读取用户信息,通过用户的添加账户能力初始化用户信息
    user1.get_accounts(bank1)
    # 显示所有用户信息
    user1.show()
    main()
