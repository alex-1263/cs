class schoolmember: #定义一个学校成员类
    def __init__(self,name,age,sex,*mylist):
        #初始化学校成员的姓名，年龄，性别，成绩列表
        self._name=name
        self._age=age
        self._sex=sex
        self._mylist=mylist
    def get_name(self):
        return self._name
    def get_age(self):
        return self._age
    def get_sex(self):
        return self._sex
    def get_avg(self):
        sum=0
        for i in self._mylist:
            sum+=i
        return sum/len(self._mylist)

class student(schoolmember):#定义一个学生类，继承学校成员类
    def get_avg(self):
        avg=super().get_avg()
        return avg
    def __str__(self):
        return "我叫"+str(super().get_name())+"，我是一名学生"

class teacher(schoolmember):#定义一个教师类,继承学校成员类
    #从列表获得所带学生的平均成绩
    def get_avg(self):
        sum=0
        for i in self._mylist:
            sum+=i.get_avg() 
        avg=sum/len(self._mylist)
        print("我带的班级的平均成绩为:",avg)
    def __str__(self):
        return "我叫"+str(super().get_name())+"，我是一名老师"
    
if __name__=="__main__":
    lisa=schoolmember("李莎",20,"女",*(80,90,100,88))
    
    print("lisa的年龄为:",lisa.get_age())
    print("lisa的性别是:",lisa.get_sex())
    print("lisa带的班级的平均成绩:",lisa.get_avg())
    print(lisa)
    print("--------------------") 
    print("测试子类")
    stu=student("张三",19,"男",*(80,90,70))
    print(stu)
    print("stu的年龄为:",stu.get_age())
    print("stu的平均成绩为:",stu.get_avg())
    stu1=student("李四",20,"男",*(80,90,100))
    print(stu1)
    print("stu1的年龄为:",stu1.get_age())
    print("stu1的平均成绩为:",stu1.get_avg())
    stu2=student("王五",21,"男",*(100,100,100))
    print(stu2)
    print("stu2的年龄为:",stu2.get_age())
    print("stu2的平均成绩为:",stu2.get_avg())
    xiaoming=teacher("小明",20,"男",*(stu,stu1,stu2))
    print(xiaoming)
    xiaoming.get_avg()
    
   
    