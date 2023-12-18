import pymysql
from config import DB_CONFIG
from models import Student
from db import Database  # 确保从实际代码中导入 Database 类

# 创建 Database 类的实例
db = Database()

# 创建一个测试学生
test_student = Student(name="张三", student_id="12345", class_name="A101", dormitory_id="D1")

# 测试添加学生
success, error_message = db.add_student(test_student)
if success:
    print("学生添加成功。")
else:
    print(f"添加学生失败。错误信息：{error_message}")

# 测试更新学生信息
success, error_message = db.update_student("12345", "李四", "B202", "D2")
if success:
    print("学生信息更新成功。")
else:
    print(f"更新学生信息失败。错误信息：{error_message}")

# 测试按学号或宿舍号查询学生
query_text = "12345"
records, error_message = db.query_records(query_text)
if records:
    print("找到的学生：")
    for record in records:
        print(record)
else:
    print(f"查询学生失败。错误信息：{error_message}")

# 测试创建宿舍
success, error_message = db.create_dormitory("D103", 5)
if success:
    print("宿舍创建成功。")
else:
    print(f"创建宿舍失败。错误信息：{error_message}")

# 测试查询所有宿舍
dormitories, error_message = db.query_dormitories()
if dormitories:
    print("所有宿舍：")
    for dormitory in dormitories:
        print(dormitory)
else:
    print(f"查询宿舍失败。错误信息：{error_message}")


# 测试查询空闲宿舍
vacant_dormitories, error_message = db.query_vacant_dormitories()
if vacant_dormitories:
    print("空闲宿舍：")
    for dormitory in vacant_dormitories:
        print(dormitory)
else:
    print(f"查询空闲宿舍失败。错误信息：{error_message}")

# 测试按班级查询学生
class_name = "计算机科学与技术1班"
students_by_class, error_message = db.query_students_by_class(class_name)
if students_by_class:
    print(f"{class_name} 班级的学生：")
    for student in students_by_class:
        print(student)
else:
    print(f"按班级查询学生失败。错误信息：{error_message}")
# 测试按班级查询学生
class_name = "11"
students_by_class, error_message = db.query_students_by_class(class_name)
if students_by_class:
    print(f"{class_name} 班级的学生：")
    for student in students_by_class:
        print(student)
else:
    print(f"按班级查询学生失败。错误信息：{error_message}")
# 测试按宿舍号查询学生
dormitory_id = "D1"
students_by_dormitory, error_message = db.query_students_by_dormitory(dormitory_id)
if students_by_dormitory:
    print(f"{dormitory_id} 宿舍的学生：")
    for student in students_by_dormitory:
        print(student)
else:
    print(f"按宿舍号查询学生失败。错误信息：{error_message}")

# 测试按姓名查询学生
student_name = "王五"
students_by_name, error_message = db.query_students_by_name(student_name)
if students_by_name:
    print(f"姓名为 {student_name} 的学生：")
    for student in students_by_name:
        print(student)
else:
    print(f"按姓名查询学生失败。错误信息：{error_message}")

# 关闭数据库连接
db.close_connection()
