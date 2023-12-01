def digit_sum(x):
    # 计算数位和
    return sum(map(int, str(x)))

def count_equation_solutions(a, b, c):
    # 计算数位和范围
    min_digit_sum = a
    max_digit_sum = 9 * len(str(10**12))  # 10^12 最多有 13 位，每位都是 9

    count = 0

    for digit_sum_z in range(min_digit_sum, max_digit_sum + 1):
        if (2 - c) % b == 0 and (2 - c) // b == digit_sum_z:
            count += 1

    return count

# 输入三个正整数 a, b, c
a, b, c = map(int, input().split())

# 计算方程解的个数并输出结果
result = count_equation_solutions(a, b, c)
print(result)
