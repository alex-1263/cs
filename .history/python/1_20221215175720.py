import random

flag = 0    # 单次实验是否成功flag
counter = 0     # 实验成功次数counter
fcounter = 0    # 单个囚徒打开抽屉次数fcounter
N = 10000   # 设置试验次数
A = list(range(100))
random.shuffle(A)   # 抽屉置乱
for i in range(N):
    flag = 1
    # experiment begins
    for j in range(100):
        k = j
        while(A[k] != j and fcounter < 50):
            k = A[k]
            fcounter += 1
        if(fcounter >= 50):
            flag = 0
            fcounter = 0
            break
        fcounter = 0

    if(flag == 1):
        counter += 1
    flag = 0
    random.shuffle(A)
print('Success Rate: ' + str(counter/N))