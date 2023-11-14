class npc:
    def __init__(self,name,job,age,hobby):
        self.name=name
        self.job=job
        self.age=age
        self.hobby=hobby
    def show_info(self):
        print("你好,我叫%s,今年%s岁,职业是%s,爱好是%s"%(self.name,self.age,self.job,self.hobby))
a =npc("aaa","student",19,"run")
a.show_info()