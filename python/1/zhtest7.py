import tkinter as tk
from tkinter import messagebox

# 存储多个用户的用户名和密码
users = {
    'admin': 'password',
    'user1': 'pass123',
    'user2': 'qwerty'
}

def check_login(username, password):
    # 检查用户名和密码是否匹配字典中的任何一项
    return username in users and users[username] == password

def on_login_button_click():
    # 获取用户名和密码
    entered_username = username_entry.get()
    entered_password = password_entry.get()

    if check_login(entered_username, entered_password):
        # 登录成功，创建新界面
        messagebox.showinfo("登录成功", "欢迎使用本系统")
        # 跳转新窗口,并创建新窗口,并设置窗口大小
        root.destroy()
        root1 = tk.Tk()
        root1.title("系统界面")
        root1.geometry("400x300")
        # 添加标签
        label = tk.Label(root1, text="欢迎使用本系统")
        #欢迎xx用户
        label1 = tk.Label(root1, text="欢迎"+entered_username+"用户")
        label1.pack()
        label.pack()
        # 添加按钮
        button = tk.Button(root1, text="退出", command=root1.destroy)
        button.pack()
        
        # 运行主循环
        root1.mainloop()





    else:
        # 登录失败，显示错误提示
        messagebox.showerror("登录失败", "用户名或密码错误")

def on_cancel_button_click():
    # 询问是否确认退出
    result = messagebox.askokcancel("确认退出", "是否确定退出系统?")
    if result:
        root.destroy()

def on_close_window():#
    # 询问是否确认退出
    result = messagebox.askokcancel("确认退出", "是否确定退出系统?")
    if result:
        root.destroy()

# 创建主窗口
root = tk.Tk()
root.title("系统登录界面")

# 添加用户名标签和输入框，默认用户名为'admin'
username_label = tk.Label(root, text="用户名:")
username_label.grid(row=0, column=0, padx=10, pady=10)
username_entry = tk.Entry(root, width=20)
username_entry.grid(row=0, column=1, padx=10, pady=10)
username_entry.insert(0, "admin")

# 添加密码标签和输入框，密码为隐式显示
password_label = tk.Label(root, text="密码:")
password_label.grid(row=1, column=0, padx=10, pady=10)
password_entry = tk.Entry(root, show="*", width=20)
password_entry.grid(row=1, column=1, padx=10, pady=10)

# 添加登录和取消按钮
login_button = tk.Button(root, text="登录", command=on_login_button_click)
login_button.grid(row=2, column=0, columnspan=2, pady=10)
cancel_button = tk.Button(root, text="取消", command=on_cancel_button_click)
cancel_button.grid(row=3, column=0, columnspan=2, pady=10)

# 监听窗口关闭事件
root.protocol("WM_DELETE_WINDOW", on_close_window)

# 运行主循环
root.mainloop()
