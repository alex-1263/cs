import pymysql
from config import DB_CONFIG


def query_students_by_name(name):
    try:
        # 建立数据库连接
        conn = pymysql.connect(**DB_CONFIG)

        with conn.cursor() as cursor:
            # 定义用于按姓名检索学生的SQL查询
            sql = "SELECT * FROM students WHERE name = %s"
            cursor.execute(sql, (name,))

            # 获取所有匹配的记录
            students = cursor.fetchall()

            if students:
                print("匹配的学生：")
                for student in students:
                    print(f"学生ID：{student[1]}")
                    print(f"姓名：{student[0]}")
                    print(f"班级：{student[2]}")
                    print(f"宿舍号：{student[3]}")
            else:
                print("未找到匹配的学生。")
    except Exception as e:
        print(f"发生错误：{e}")
    finally:
        # 关闭数据库连接
        if conn:
            conn.close()


if __name__ == "__main__":
    # 输入要搜索的学生姓名
    search_name = input("请输入要搜索的学生姓名：")
    query_students_by_name(search_name)
