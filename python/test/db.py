import pymysql
from config import DB_CONFIG
from models import Student

class Database:
    def __init__(self):
        self.conn = pymysql.connect(**DB_CONFIG)

    def add_student(self, student):
        try:
            with self.conn.cursor() as cursor:
                sql = "INSERT INTO students (name, student_id, class_name, dormitory_id) VALUES (%s, %s, %s, %s)"
                cursor.execute(sql, (student.name, student.student_id, student.class_name, student.dormitory_id))
            self.conn.commit()
            return True, None  # 添加成功返回True和无错误消息
        except pymysql.IntegrityError as e:
            # 处理唯一键冲突的情况，例如学号重复
            return False, "学号重复，请检查输入"
        except Exception as e:
            return False, f"添加学生出错: {e}"

    def delete_student(self, student_id):
        try:
            with self.conn.cursor() as cursor:
                sql = "DELETE FROM students WHERE student_id = %s"
                cursor.execute(sql, (student_id,))
            self.conn.commit()
            if cursor.rowcount > 0:
                return True, None  # 删除成功返回True和无错误消息
            else:
                return False, "未找到匹配的学生记录"
        except Exception as e:
            return False, f"删除学生出错: {e}"

    def update_student(self, student_id, new_name, new_class_name, new_dormitory_id):
        try:
            with self.conn.cursor() as cursor:
                # 编写更新学生信息的SQL语句
                sql = "UPDATE students SET name = %s, class_name = %s, dormitory_id = %s WHERE student_id = %s"
                cursor.execute(sql, (new_name, new_class_name, new_dormitory_id, student_id))
            self.conn.commit()
            if cursor.rowcount > 0:
                return True, None  # 更新成功返回True和无错误消息
            else:
                return False, "未找到匹配的学生记录"
        except Exception as e:
            return False, f"更新学生信息出错: {e}"

    def update_dormitory(self, dormitory_id):
        try:
            with self.conn.cursor() as cursor:
                sql = "UPDATE dormitories SET current_number = current_number + 1 WHERE dormitory_id = %s"
                cursor.execute(sql, (dormitory_id,))
            self.conn.commit()
            if cursor.rowcount > 0:
                return True, None  # 更新成功返回True和无错误消息
            else:
                return False, "未找到匹配的宿舍记录"
        except Exception as e:
            return False, f"更新宿舍信息出错: {e}"

    def query_records(self, query_text):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM students WHERE student_id = %s OR dormitory_id = %s"
                cursor.execute(sql, (query_text, query_text))
                records = cursor.fetchall()
                return records, None  # 查询成功返回查询结果和无错误消息
        except Exception as e:
            return None, f"查询记录出错: {e}"
    #创建宿舍
    def create_dormitory(self, dormitory_id, capacity):
        try:
            with self.conn.cursor() as cursor:
                sql = "INSERT INTO dormitories (dormitory_id, capacity, current_number) VALUES (%s, %s, 0)"
                cursor.execute(sql, (dormitory_id, capacity))
            self.conn.commit()
            return True, None  # 创建成功返回True和无错误消息
        except pymysql.IntegrityError as e:
            # 处理唯一键冲突的情况，例如宿舍号重复
            return False, "宿舍号重复，请检查输入"
        except Exception as e:
            return False, f"创建宿舍出错: {e}"

    def delete_dormitory(self, dormitory_id):
        try:
            with self.conn.cursor() as cursor:
                sql = "DELETE FROM dormitories WHERE dormitory_id = %s"
                cursor.execute(sql, (dormitory_id,))
            self.conn.commit()
            if cursor.rowcount > 0:
                return True, None  # 删除成功返回True和无错误消息
            else:
                return False, "未找到匹配的宿舍记录"
        except Exception as e:
            return False, f"删除宿舍出错: {e}"

    def query_dormitories(self):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM dormitories"
                cursor.execute(sql)
                dormitories = cursor.fetchall()
                return dormitories, None  # 查询成功返回查询结果和无错误消息
        except Exception as e:
            return None, f"查询宿舍记录出错: {e}"

    def batch_add_students(self, students):
        try:
            with self.conn.cursor() as cursor:
                sql = "INSERT INTO students (name, student_id, class_name, dormitory_id) VALUES (%s, %s, %s, %s)"
                cursor.executemany(sql,
                                   [(student.name, student.student_id, student.class_name, student.dormitory_id) for
                                    student in students])
            self.conn.commit()
            return True, None
        except Exception as e:
            return False, f"批量添加学生出错: {e}"

    def query_vacant_dormitories(self):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM dormitories WHERE current_number < capacity"
                cursor.execute(sql)
                dormitories = cursor.fetchall()
                return dormitories, None
        except Exception as e:
            return None, f"查询空闲宿舍出错: {e}"

    def query_students_by_class(self, class_name):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM students WHERE class_name = %s"
                cursor.execute(sql, (class_name,))
                students = cursor.fetchall()
                return students, None
        except Exception as e:
            return None, f"按班级查询学生出错: {e}"

    def query_students_by_dormitory(self, dormitory_id):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM students WHERE dormitory_id = %s"
                cursor.execute(sql, (dormitory_id,))
                students = cursor.fetchall()
                return students, None  # 查询成功返回学生记录和无错误消息
        except Exception as e:
            return None, f"按宿舍号查询学生出错: {e}"

    def remove_student_from_dormitory(self, student_id):
        try:
            with self.conn.cursor() as cursor:
                sql = "UPDATE students SET dormitory_id = NULL WHERE student_id = %s"
                cursor.execute(sql, (student_id,))
            self.conn.commit()
            if cursor.rowcount > 0:
                return True, None  # 更新成功返回True和无错误消息
            else:
                return False, "未找到匹配的学生记录"
        except Exception as e:
            return False, f"从宿舍中删除学生出错: {e}"

    def query_students_by_name(self, student_name):
        try:
            with self.conn.cursor() as cursor:
                sql = "SELECT * FROM students WHERE name = %s"
                cursor.execute(sql, (student_name,))
                students = cursor.fetchall()
                return students, None  # 查询成功返回学生记录和无错误消息
        except Exception as e:
            return None, f"按姓名查询学生出错: {e}"
    def close_connection(self):
        self.conn.close()

