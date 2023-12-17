class Student:
    def __init__(self, student_id, name, class_name, dormitory_id):
        self.student_id = student_id
        self.name = name
        self.class_name = class_name
        self.dormitory_id = dormitory_id

    def __str__(self):
        return f"Student ID: {self.student_id}, Name: {self.name}, Class: {self.class_name}, Dormitory ID: {self.dormitory_id}"

class Dormitory:
    def __init__(self, dormitory_id, capacity):
        self.dormitory_id = dormitory_id
        self.capacity = capacity

    def __str__(self):
        return f"Dormitory ID: {self.dormitory_id}, Capacity: {self.capacity}"

    def is_full(self):
        # 检查宿舍是否已满
        # 可以根据实际需求定义满员的条件
        pass
