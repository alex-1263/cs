import tkinter as tk
from tkinter import ttk, messagebox
from db import Database
from models import Student, Dormitory
import tkinter as tk
from tkinter import messagebox
from tkinter import ttk  # 导入ttk


class MainApplication:
    def __init__(self, root):
        self.root = root
        self.root.title("宿舍管理系统")

        self.db = Database()
        self.setup_welcome_screen()

    def setup_welcome_screen(self):
        self.welcome_label = tk.Label(self.root, text="欢迎使用宿舍管理系统", font=("Helvetica", 18))
        self.welcome_label.pack(pady=20)

        self.dorm_management_button = tk.Button(self.root, text="宿舍信息管理", command=self.open_dorm_management)
        self.dorm_management_button.pack(pady=10)

        self.student_management_button = tk.Button(self.root, text="宿舍人员信息管理",
                                                   command=self.open_student_management)
        self.student_management_button.pack(pady=10)

        self.query_system_button = tk.Button(self.root, text="查询系统", command=self.open_query_system)
        self.query_system_button.pack(pady=10)

    def open_dorm_management(self):
        self.root.withdraw()  # 隐藏主窗口
        dorm_management_window = tk.Toplevel(self.root)
        dorm_management_window.title("宿舍信息管理")

        welcome_label = tk.Label(dorm_management_window, text="欢迎进入宿舍信息管理", font=("Helvetica", 16))
        welcome_label.pack(pady=10)

        add_button = tk.Button(dorm_management_window, text="添加宿舍记录", command=self.add_dormitory)
        add_button.pack(pady=5)

        delete_button = tk.Button(dorm_management_window, text="删除宿舍记录", command=self.delete_dormitory)
        delete_button.pack(pady=5)


        back_button = tk.Button(dorm_management_window, text="返回",
                                command=lambda: self.close_window(dorm_management_window))
        back_button.pack(pady=10)

    def add_dormitory(self):
        add_dorm_window = tk.Toplevel(self.root)
        add_dorm_window.title("添加宿舍")

        tk.Label(add_dorm_window, text="宿舍号").pack(pady=5)
        dormitory_id_entry = tk.Entry(add_dorm_window)
        dormitory_id_entry.pack(pady=5)

        tk.Label(add_dorm_window, text="容纳人数").pack(pady=5)
        capacity_entry = tk.Entry(add_dorm_window)
        capacity_entry.pack(pady=5)

        submit_button = tk.Button(add_dorm_window, text="添加宿舍", command=lambda: self.submit_dormitory(dormitory_id_entry.get(), capacity_entry.get()))
        submit_button.pack(pady=10)

    def submit_dormitory(self, dormitory_id, capacity):
        try:
            capacity = int(capacity)
        except ValueError:
            messagebox.showerror("错误", "容纳人数必须是数字")
            return

        success, message = self.db.create_dormitory(dormitory_id, capacity)
        if success:
            messagebox.showinfo("成功", "宿舍添加成功")
        else:
            messagebox.showerror("错误", message)

    def delete_dormitory(self):
        delete_dorm_window = tk.Toplevel(self.root)
        delete_dorm_window.title("删除宿舍")

        tk.Label(delete_dorm_window, text="宿舍号").pack(pady=5)
        dormitory_id_entry = tk.Entry(delete_dorm_window)
        dormitory_id_entry.pack(pady=5)

        submit_button = tk.Button(delete_dorm_window, text="删除宿舍",
                                  command=lambda: self.submit_delete_dormitory(dormitory_id_entry.get()))
        submit_button.pack(pady=10)

    def submit_delete_dormitory(self, dormitory_id):
        success, message = self.db.delete_dormitory(dormitory_id)
        if success:
            messagebox.showinfo("成功", "宿舍删除成功")
        else:
            messagebox.showerror("错误", message)


    def open_student_management(self):
        self.root.withdraw()  # 隐藏主窗口
        student_management_window = tk.Toplevel(self.root)
        student_management_window.title("宿舍人员信息管理")

        welcome_label = tk.Label(student_management_window, text="欢迎进入宿舍人员信息管理", font=("Helvetica", 16))
        welcome_label.pack(pady=10)

        add_button = tk.Button(student_management_window, text="添加宿舍人员记录", command=self.add_student)
        add_button.pack(pady=5)

        delete_button = tk.Button(student_management_window, text="删除宿舍人员记录", command=self.delete_student)
        delete_button.pack(pady=5)

        update_button = tk.Button(student_management_window, text="修改宿舍人员记录", command=self.update_student)
        update_button.pack(pady=5)

        back_button = tk.Button(student_management_window, text="返回",
                                command=lambda: self.close_window(student_management_window))
        back_button.pack(pady=10)

    def add_student(self):
        add_student_window = tk.Toplevel(self.root)
        add_student_window.title("添加宿舍人员记录")

        tk.Label(add_student_window, text="学号").pack(pady=5)
        student_id_entry = tk.Entry(add_student_window)
        student_id_entry.pack(pady=5)

        tk.Label(add_student_window, text="姓名").pack(pady=5)
        name_entry = tk.Entry(add_student_window)
        name_entry.pack(pady=5)

        tk.Label(add_student_window, text="班级").pack(pady=5)
        class_name_entry = tk.Entry(add_student_window)
        class_name_entry.pack(pady=5)

        tk.Label(add_student_window, text="宿舍号").pack(pady=5)
        dormitory_id_entry = tk.Entry(add_student_window)
        dormitory_id_entry.pack(pady=5)

        # 创建一个添加按钮，用于将学生添加到宿舍
        add_button = tk.Button(add_student_window, text="添加学生",
                               command=lambda: self.submit_student(student_id_entry.get(), name_entry.get(),
                                                                   class_name_entry.get(), dormitory_id_entry.get(),
                                                                   add_student_window))
        add_button.pack(pady=10)

    def submit_student(self, student_id, name, class_name, dormitory_id, add_student_window):
        # 在此方法中执行将学生添加到宿舍的操作
        # 使用 self.db.add_student() 方法将学生信息添加到数据库

        success, message = self.db.add_student(Student(student_id, name, class_name, dormitory_id))

        if success:
            messagebox.showinfo("成功", "学生添加成功")
            add_student_window.destroy()  # 关闭添加学生窗口
        else:
            messagebox.showerror("错误", message)

    def delete_student(self):
        # 创建删除学生记录的窗口
        delete_student_window = tk.Toplevel(self.root)
        delete_student_window.title("删除学生记录")

        # 添加标签和输入框，用于输入学生学号
        tk.Label(delete_student_window, text="学号").pack(pady=5)
        student_id_entry = tk.Entry(delete_student_window)
        student_id_entry.pack(pady=5)

        # 创建一个删除按钮，用于删除学生记录
        delete_button = tk.Button(delete_student_window, text="删除学生",
                                  command=lambda: self.submit_delete_student(student_id_entry.get(),
                                                                             delete_student_window))
        delete_button.pack(pady=10)

    def submit_delete_student(self, student_id, delete_student_window):
        # 在此方法中执行删除学生记录的操作
        # 使用 self.db.delete_student() 方法删除学生记录

        success, message = self.db.delete_student(student_id)

        if success:
            messagebox.showinfo("成功", "学生记录删除成功")
            delete_student_window.destroy()  # 关闭删除学生记录窗口
        else:
            messagebox.showerror("错误", message)

    def update_student(self):
        # 创建修改学生记录的窗口
        update_student_window = tk.Toplevel(self.root)
        update_student_window.title("修改学生记录")

        # 添加标签和输入框，用于输入学生学号、新姓名、新班级、新宿舍号
        tk.Label(update_student_window, text="学号").pack(pady=5)
        student_id_entry = tk.Entry(update_student_window)
        student_id_entry.pack(pady=5)

        tk.Label(update_student_window, text="新姓名").pack(pady=5)
        new_name_entry = tk.Entry(update_student_window)
        new_name_entry.pack(pady=5)

        tk.Label(update_student_window, text="新班级").pack(pady=5)
        new_class_name_entry = tk.Entry(update_student_window)
        new_class_name_entry.pack(pady=5)

        tk.Label(update_student_window, text="新宿舍号").pack(pady=5)
        new_dormitory_id_entry = tk.Entry(update_student_window)
        new_dormitory_id_entry.pack(pady=5)

        # 创建一个修改按钮，用于修改学生记录
        update_button = tk.Button(update_student_window, text="修改学生",
                                  command=lambda: self.submit_update_student(student_id_entry.get(),
                                                                             new_name_entry.get(),
                                                                             new_class_name_entry.get(),
                                                                             new_dormitory_id_entry.get(),
                                                                             update_student_window))
        update_button.pack(pady=10)

    def submit_update_student(self, student_id, new_name, new_class_name, new_dormitory_id, update_student_window):
        # 在此方法中执行修改学生记录的操作
        # 使用 self.db.update_student() 方法修改学生记录

        success, message = self.db.update_student(student_id, new_name, new_class_name, new_dormitory_id)

        if success:
            messagebox.showinfo("成功", "学生记录修改成功")
            update_student_window.destroy()  # 关闭修改学生记录窗口
        else:
            messagebox.showerror("错误", message)

    def open_query_system(self):
        self.root.withdraw()  # 隐藏主窗口
        query_system_window = tk.Toplevel(self.root)
        query_system_window.title("查询系统")

        welcome_label = tk.Label(query_system_window, text="欢迎进入查询系统", font=("Helvetica", 16))
        welcome_label.pack(pady=10)

        query_by_name_button = tk.Button(query_system_window, text="按姓名查询", command=self.query_by_name)
        query_by_name_button.pack(pady=5)

        query_by_student_id_button = tk.Button(query_system_window, text="按学号查询", command=self.query_by_student_id)
        query_by_student_id_button.pack(pady=5)

        query_by_dormitory_button = tk.Button(query_system_window, text="按宿舍查询", command=self.query_by_dormitory)
        query_by_dormitory_button.pack(pady=5)

        empty_dormitories_button = tk.Button(query_system_window, text="空宿舍查询", command=self.empty_dormitories)
        empty_dormitories_button.pack(pady=5)

        back_button = tk.Button(query_system_window, text="返回",
                                command=lambda: self.close_window(query_system_window))
        back_button.pack(pady=10)

    def query_by_name(self):
        # 创建按姓名查询的窗口
        query_name_window = tk.Toplevel(self.root)
        query_name_window.title("按姓名查询学生")

        # 添加标签和输入框，用于输入学生姓名
        tk.Label(query_name_window, text="姓名").pack(pady=5)
        student_name_entry = tk.Entry(query_name_window)
        student_name_entry.pack(pady=5)

        # 创建一个查询按钮，用于执行按姓名查询
        query_button = tk.Button(query_name_window, text="查询",
                                 command=lambda: self.submit_query_by_name(student_name_entry.get(), query_name_window))
        query_button.pack(pady=10)

        # 创建一个帧，用于包装列表框和滚动条
        result_frame = tk.Frame(query_name_window)
        result_frame.pack(pady=10)

        # 创建一个列表框，用于显示查询结果
        result_listbox = tk.Listbox(result_frame, width=40, height=10)
        result_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # 创建垂直滚动条，并绑定到列表框
        scrollbar_y = tk.Scrollbar(result_frame, orient=tk.VERTICAL)
        scrollbar_y.pack(side=tk.RIGHT, fill=tk.Y)
        result_listbox.config(yscrollcommand=scrollbar_y.set)
        scrollbar_y.config(command=result_listbox.yview)

        # 创建水平滚动条，并绑定到列表框
        scrollbar_x = tk.Scrollbar(result_frame, orient=tk.HORIZONTAL)
        scrollbar_x.pack(side=tk.BOTTOM, fill=tk.X)
        result_listbox.config(xscrollcommand=scrollbar_x.set)
        scrollbar_x.config(command=result_listbox.xview)

        self.result_listbox = result_listbox  # 保存列表框的引用以便后续更新结果

    def submit_query_by_name(self, student_name, query_name_window):
        # 在此方法中执行按姓名查询的操作
        # 使用 self.db.query_students_by_name() 方法查询学生记录

        students, error_message = self.db.query_students_by_name(student_name)

        if students is not None:
            # 清空列表框
            self.result_listbox.delete(0, tk.END)

            if not students:
                self.result_listbox.insert(tk.END, "未找到匹配的学生记录")
            else:
                # 在列表框中显示查询结果
                for student in students:
                    self.result_listbox.insert(tk.END,
                                               f"学号: {student[1]}, 姓名: {student[0]}, 班级: {student[2]}, 宿舍号: {student[3]}")
        else:
            messagebox.showerror("错误", error_message)

    def query_by_student_id(self):
        # 创建按学号查询的窗口
        query_id_window = tk.Toplevel(self.root)
        query_id_window.title("按学号查询学生")

        # 添加标签和输入框，用于输入学生学号
        tk.Label(query_id_window, text="学号").pack(pady=5)
        student_id_entry = tk.Entry(query_id_window)
        student_id_entry.pack(pady=5)

        # 创建一个查询按钮，用于执行按学号查询
        query_button = tk.Button(query_id_window, text="查询",
                                 command=lambda: self.submit_query_by_student_id(student_id_entry.get(),
                                                                                 query_id_window))
        query_button.pack(pady=10)

        # 创建一个帧，用于包装列表框和滚动条
        result_frame = tk.Frame(query_id_window)
        result_frame.pack(pady=10)

        # 创建一个列表框，用于显示查询结果
        result_listbox = tk.Listbox(result_frame, width=40, height=10)
        result_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # 创建垂直滚动条，并绑定到列表框
        scrollbar_y = tk.Scrollbar(result_frame, orient=tk.VERTICAL)
        scrollbar_y.pack(side=tk.RIGHT, fill=tk.Y)
        result_listbox.config(yscrollcommand=scrollbar_y.set)
        scrollbar_y.config(command=result_listbox.yview)

        # 创建水平滚动条，并绑定到列表框
        scrollbar_x = tk.Scrollbar(result_frame, orient=tk.HORIZONTAL)
        scrollbar_x.pack(side=tk.BOTTOM, fill=tk.X)
        result_listbox.config(xscrollcommand=scrollbar_x.set)
        scrollbar_x.config(command=result_listbox.xview)

        self.result_listbox = result_listbox  # 保存列表框的引用以便后续更新结果

    def submit_query_by_student_id(self, student_id, query_id_window):
        # 在此方法中执行按学号查询的操作
        # 使用 self.db.query_records() 方法查询学生记录

        records, error_message = self.db.query_records(student_id)

        if records is not None:
            # 显示查询结果
            self.display_results(records)
        else:
            messagebox.showerror("错误", error_message)

    def display_results(self, records):
        # 在列表框中显示查询结果
        self.result_listbox.delete(0, tk.END)  # 清空列表框

        if not records:
            self.result_listbox.insert(tk.END, "未找到匹配的学生记录")
        else:
            for record in records:
                # 格式化查询结果并插入列表框
                formatted_record = f"学号: {record[1]}, 姓名: {record[0]}, 班级: {record[2]}, 宿舍号: {record[3]}"
                self.result_listbox.insert(tk.END, formatted_record)

    def query_by_dormitory(self):
        # 创建按宿舍查询的窗口
        query_dormitory_window = tk.Toplevel(self.root)
        query_dormitory_window.title("按宿舍查询学生")

        # 添加标签和输入框，用于输入宿舍号
        tk.Label(query_dormitory_window, text="宿舍号").pack(pady=5)
        dormitory_id_entry = tk.Entry(query_dormitory_window)
        dormitory_id_entry.pack(pady=5)

        # 创建一个查询按钮，用于执行按宿舍查询
        query_button = tk.Button(query_dormitory_window, text="查询",
                                 command=lambda: self.submit_query_by_dormitory(dormitory_id_entry.get(),
                                                                                query_dormitory_window))
        query_button.pack(pady=10)

        # 创建一个帧，用于包装列表框和滚动条
        result_frame = tk.Frame(query_dormitory_window)
        result_frame.pack(pady=10)

        # 创建一个列表框，用于显示查询结果
        result_listbox = tk.Listbox(result_frame, width=40, height=10)
        result_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # 创建垂直滚动条，并绑定到列表框
        scrollbar_y = tk.Scrollbar(result_frame, orient=tk.VERTICAL)
        scrollbar_y.pack(side=tk.RIGHT, fill=tk.Y)
        result_listbox.config(yscrollcommand=scrollbar_y.set)
        scrollbar_y.config(command=result_listbox.yview)

        # 创建水平滚动条，并绑定到列表框
        scrollbar_x = tk.Scrollbar(result_frame, orient=tk.HORIZONTAL)
        scrollbar_x.pack(side=tk.BOTTOM, fill=tk.X)
        result_listbox.config(xscrollcommand=scrollbar_x.set)
        scrollbar_x.config(command=result_listbox.xview)

        self.result_listbox = result_listbox  # 保存列表框的引用以便后续更新结果

    def submit_query_by_dormitory(self, dormitory_id, query_dormitory_window):
        # 在此方法中执行按宿舍查询的操作
        # 使用 self.db.query_students_by_dormitory() 方法查询学生记录

        students, error_message = self.db.query_students_by_dormitory(dormitory_id)

        if students is not None:
            # 显示查询结果
            self.display_results(students)
        else:
            messagebox.showerror("错误", error_message)

    def display_results(self, students):
        # 在列表框中显示查询结果
        self.result_listbox.delete(0, tk.END)  # 清空列表框

        if not students:
            self.result_listbox.insert(tk.END, "未找到匹配的学生记录")
        else:
            for student in students:
                # 格式化查询结果并插入列表框
                formatted_student = f"学号: {student[1]}, 姓名: {student[0]}, 班级: {student[2]}, 宿舍号: {student[3]}"
                self.result_listbox.insert(tk.END, formatted_student)

    def empty_dormitories(self):
        # 创建空宿舍查询的窗口
        empty_dormitories_window = tk.Toplevel(self.root)
        empty_dormitories_window.title("查询空宿舍")

        # 创建一个查询按钮，用于执行空宿舍查询
        query_button = tk.Button(empty_dormitories_window, text="查询",
                                 command=lambda: self.submit_empty_dormitories(empty_dormitories_window))
        query_button.pack(pady=10)

        # 创建一个帧，用于包装列表框和滚动条
        result_frame = tk.Frame(empty_dormitories_window)
        result_frame.pack(pady=10)

        # 创建一个列表框，用于显示查询结果
        result_listbox = tk.Listbox(result_frame, width=40, height=10)
        result_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # 创建垂直滚动条，并绑定到列表框
        scrollbar_y = tk.Scrollbar(result_frame, orient=tk.VERTICAL)
        scrollbar_y.pack(side=tk.RIGHT, fill=tk.Y)
        result_listbox.config(yscrollcommand=scrollbar_y.set)
        scrollbar_y.config(command=result_listbox.yview)

        # 创建水平滚动条，并绑定到列表框
        scrollbar_x = tk.Scrollbar(result_frame, orient=tk.HORIZONTAL)
        scrollbar_x.pack(side=tk.BOTTOM, fill=tk.X)
        result_listbox.config(xscrollcommand=scrollbar_x.set)
        scrollbar_x.config(command=result_listbox.xview)

        self.result_listbox = result_listbox  # 保存列表框的引用以便后续更新结果

    def submit_empty_dormitories(self, empty_dormitories_window):
        # 在此方法中执行空宿舍查询的操作
        # 使用 self.db.query_vacant_dormitories() 方法查询空宿舍

        vacant_dormitories, error_message = self.db.query_vacant_dormitories()

        if vacant_dormitories is not None:
            # 显示查询结果
            self.display_results(vacant_dormitories)
        else:
            messagebox.showerror("错误", error_message)

    def display_results(self, dormitories):
        # 在列表框中显示查询结果
        self.result_listbox.delete(0, tk.END)  # 清空列表框

        if not dormitories:
            self.result_listbox.insert(tk.END, "没有空宿舍")
        else:
            for dormitory in dormitories:
                # 格式化查询结果并插入列表框
                formatted_dormitory = f"宿舍号: {dormitory[0]}, 容纳人数: {dormitory[1]}, 当前人数: {dormitory[2]}"
                self.result_listbox.insert(tk.END, formatted_dormitory)

    def close_window(self, window):
        window.destroy()  # 关闭当前窗口
        self.root.deiconify()  # 恢复主窗口的显示


if __name__ == "__main__":
    root = tk.Tk()
    app = MainApplication(root)
    root.mainloop()
