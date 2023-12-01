import tkinter as tk
# 定义加法函数
def add():
    a = float(E1.get())
    b = float(E2.get())
    s = "{:7.2f} + {:7.2f} = {:7.2f}\n".format(a,b,a+b)
    txt.insert(tk.END,s)
    E1.delete(0,tk.END)
    E2.delete(0,tk.END)
# 定义减法函数
def sub(x,y):
    s = "{:7.2f} - {:7.2f} = {:7.2f}\n".format(x,y,x-y)
    txt.insert(1.0,s)
    E1.delete(0,tk.END)
    E2.delete(0,tk.END)
# 创建主窗口
root = tk.Tk() # 实例化一个窗口
root.title("加减运算器")
root.geometry("300x400")
# 创建组件并布局组件
L1 = tk.Label(root,text="请输入两个数，按下面的按钮执行对应操作")
# 组件创建的时候一定要标记这个组件是放在什么上面的
L1.pack()  # 默认是top
E1 = tk.Entry(root)
# E1.place(x=30,y=80,width=120,height=30)   # 绝对位置大小
E1.place(relx=0.1,rely=0.2,relwidth=0.3,relheight=0.05)
E2 = tk.Entry(root)
E2.place(relx=0.6,rely=0.2,relwidth=0.3,relheight=0.05)
b1 = tk.Button(root,text="+",command=add)
b1.place(relx=0.1,rely=0.4,relwidth=0.3,relheight=0.05)
b2 = tk.Button(root,text="-",command=lambda:sub(float(E1.get()),float(E2.get())))
b2.place(relx=0.6,rely=0.4,relwidth=0.3,relheight=0.05)
txt = tk.Text(root)
txt.place(rely=0.6,relheight=0.4)

root.mainloop()