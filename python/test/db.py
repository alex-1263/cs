import pymysql

class Database:
    def __init__(self):
        self.conn = pymysql.connect(host='47.120.14.134', user='test', password='123456', db='ssmsdb')

    def add_student(self, student):
        # 添加学生到数据库
        pass

    def delete_student(self, student_id):
        # 从数据库删除学生
        pass

    # 其他数据库操作函数
