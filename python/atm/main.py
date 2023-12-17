import tkinter as tk
from tkinter import messagebox, simpledialog
import json

class ModernATM:
    def __init__(self, master):
        self.master = master
        self.master.geometry('500x500')  # 改为正方形窗口
        self.master.title('现代银行ATM')
        self.users = self.load_users()
        if not self.users:
            self.users = {'admin': {'password': '1234', 'balance': 1000.0}}
            self.save_users()
        self.current_user = None
        self.init_login_ui()

    def load_users(self, filename='user_data.json'):
        try:
            with open(filename, 'r') as file:
                return json.load(file)
        except FileNotFoundError:
            return {}

    def save_users(self, filename='user_data.json'):
        with open(filename, 'w') as file:
            json.dump(self.users, file, indent=4)

    def display_balance(self):
        balance = self.users[self.current_user]['balance']
        messagebox.showinfo("账户余额", f"当前余额：{balance}元")

    def perform_deposit(self):
        amount = simpledialog.askfloat("存入金额", "请输入存入金额", minvalue=0.01)
        if amount:
            self.users[self.current_user]['balance'] += amount
            messagebox.showinfo("存款成功", f"已存入：{amount}元")
            self.display_balance()

    def perform_withdrawal(self):
        amount = simpledialog.askfloat("取款", "请输入取款金额", minvalue=0.01, maxvalue=self.users[self.current_user]['balance'])
        if amount:
            self.users[self.current_user]['balance'] -= amount
            messagebox.showinfo("取款成功", f"已取出：{amount}元")
            self.display_balance()

    def init_login_ui(self):
        self.login_frame = tk.Frame(self.master)
        self.login_frame.pack(expand=True)
        tk.Label(self.login_frame, text="用户名").pack()
        self.username_entry = tk.Entry(self.login_frame)
        self.username_entry.pack()
        tk.Label(self.login_frame, text="密码").pack()
        self.password_entry = tk.Entry(self.login_frame, show='*')
        self.password_entry.pack()
        tk.Button(self.login_frame, text="登录", command=self.authenticate).pack()

    def destroy_login_ui(self):
        self.login_frame.destroy()

    def authenticate(self):
        username = self.username_entry.get()
        password = self.password_entry.get()
        if username in self.users and self.users[username]['password'] == password:
            self.current_user = username
            self.destroy_login_ui()
            self.init_atm_ui()
        else:
            messagebox.showerror("登录失败", "用户名或密码错误")

    def sign_out(self):
        self.atm_frame.destroy()
        self.init_login_ui()

    def init_atm_ui(self):
        self.atm_frame = tk.Frame(self.master)
        self.atm_frame.place(x=0, y=0, width=500, height=500)  # 占据整个窗口

        # 设置欢迎语
        welcome_label = tk.Label(self.atm_frame, text=f"欢迎，{self.current_user}！,使用atm机", font=("Arial", 16))
        welcome_label.place(relx=0.4, rely=0.4, anchor='center')

        # 按钮大小
        button_width = 200
        button_height = 50

        # 按钮放置在左上角
        balance_button = tk.Button(self.atm_frame, text="查看余额", command=self.display_balance)
        balance_button.place(x=0, y=0, width=button_width, height=button_height)

        # 按钮放置在右上角
        deposit_button = tk.Button(self.atm_frame, text="存款", command=self.perform_deposit)
        deposit_button.place(x=500 - button_width, y=0, width=button_width, height=button_height)

        # 按钮放置在左下角
        withdrawal_button = tk.Button(self.atm_frame, text="取款", command=self.perform_withdrawal)
        withdrawal_button.place(x=0, y=500 - button_height, width=button_width, height=button_height)

        # 按钮放置在右下角
        sign_out_button = tk.Button(self.atm_frame, text="退出登录", command=self.sign_out)
        sign_out_button.place(x=500 - button_width, y=500 - button_height, width=button_width, height=button_height)


# 主程序
root = tk.Tk()
atm_app = ModernATM(root)
root.mainloop()
atm_app.save_users()
