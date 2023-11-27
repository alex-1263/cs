def toggle_case(input_str):
    result_str = ""
    for char in input_str:
        if char.islower():
            result_str += char.upper()
        elif char.isupper():
            result_str += char.lower()
        else:
            result_str += char
    return result_str

# 输入字符串
input_str = input()

# 处理字符串并输出结果
output_str = toggle_case(input_str)
print(output_str)
