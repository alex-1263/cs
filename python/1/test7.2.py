import tkinter as tk
from tkinter.messagebox import *
from tkinter.simpledialog import *
class StartFrame:
    def __init__(self,root,times,right):
        self.master=root
        self.times=times
        self.right=right
        self.currenttimes=0
        self.totaltimes=0
        self.creatpage()
        
    def creatpage(self):
        self.page=tk.Frame(self.master)
        L1=tk.Label(self.page,text="欢迎进入猜数字游戏\n请点击'开始游戏'按钮进行配置",font=("黑体",20)).grid(row=0,column=0,columnspan=2)
        L1.place(relx=0.1,rely=0.2,relwidth=0.3,relheight=0.05)
        B1=tk.Button(self.page,text="开始游戏",command=self.startclick).grid(row=1,column=0)
        B1.place(relx=0.1,rely=0.4,relwidth=0.3,relheight=0.05)
        self.page.place(relx=0.5,rely=0.5,relwidth=0.3,relheight=0.05)
    def startclick(self):                    
        while True:
            start=askinteger(title="数据范围最小值",prompt="请输入数据范围最小值",initialvalue=10,minvalue=1,maxvalue=1000)
            if start != None:
                break


class PlayFrame:
    pass

class mainwin:
#创建主窗口
    def __init__(self):
        root=tk.Tk()
        root.title("猜数字游戏")
        root.geometry("500x300")
        root.protocol("WM_DELETE_WINDOW",self.closeWindow())
        self.root=root
    #全局变量记录战绩
        self.times=0
        self.right=0
    #布局组件
        StartFrame(root,self.times,self.right)

    #执行主循环
        root.mainloop()
    #定义关闭窗口函数
    def closeWindow(self):
        #showinfo("退出游戏","您一共玩了%d次，猜对了%d次，正确率为%.2f%%"%(times,right,right/times*100))
        pass
if __name__=="__main__":
    mainwin()


