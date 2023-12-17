def validate_student_data(student_name, student_id, class_name, dormitory_id):
    # 验证学生数据的合法性
    if not student_name or not student_id or not class_name or not dormitory_id:
        return False  # 如果有任何一个字段为空，返回False
    # 可以添加其他自定义的验证逻辑，例如检查学号格式等
    return True

