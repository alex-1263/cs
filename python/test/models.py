class Student:
    def __init__(self, student_id, name, class_name, dormitory_id):
        self.student_id = student_id
        self.name = name
        self.class_name = class_name
        self.dormitory_id = dormitory_id

class Dormitory:
    def __init__(self, dormitory_id, capacity):
        self.dormitory_id = dormitory_id
        self.capacity = capacity
