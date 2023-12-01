def evaluate_polynomial(coefficients, exponents, x):
    result = 0
    for coeff, exp in zip(coefficients, exponents):
        term_value = coeff * x**exp
        result += term_value
    return result

# 输入第一个多项式的系数和指数
coefficients1 = list(map(int, input().split()))
exponents1 = list(map(int, input().split()))

# 输入第二个多项式的系数和指数
coefficients2 = list(map(int, input().split()))
exponents2 = list(map(int, input().split()))

# 输入 x 的值
x_value = float(input())

# 计算两个多项式的和
coefficients_sum = [coeff1 + coeff2 for coeff1, coeff2 in zip(coefficients1, coefficients2)]
exponents_sum = exponents1 + exponents2

# 计算多项式和并带入 x 值
result = evaluate_polynomial(coefficients_sum, exponents_sum, x_value)

# 输出结果
print(result)

