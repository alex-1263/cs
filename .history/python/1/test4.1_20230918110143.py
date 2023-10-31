try:
    month_salary= float(input("请输入月工资"))
    assert 0<month_salary<30000
    year_salary=month_salary*12;
    print("月薪为%.2f的年薪为%.2f" %(month_salary,year_salary))
except ValueError:
    print("请输入数值的月薪数")
except AssertionError:
    print("请输入大于0小于30000的月薪!")