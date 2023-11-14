class schoolmember:
    def __init__(self,name,age,sex,mylist):
        self.name=name
        self.age=age
        self.sex=sex
        self.mylist=mylist
        self.cj=0
    def show_info(self):
        print("姓名:%s,性别:%s,年龄:%s,平均成绩:%s"%(self.name,self.sex,self.age,self.cj))
    def pj(self):
        sum=0
        for i in range(len(self.mylist)):
            sum+=self.mylist[i]
        self.cj=sum/len(self.mylist)
        return self.cj

aaa=schoolmember("aaa","male",19,[3,4,5])
aaa.pj()
aaa.show_info()