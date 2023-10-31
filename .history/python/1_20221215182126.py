from random import shuffle
times = 100000
T = 0
count = times
while T < times:
    box = [i+1 for i in range(100)]
    shuffle(box)
    box.insert(0,-1)
    for i in range(1,101):
        t = 50
        num = i
        while t > 0:
            num = box[num]
            if num == i:
                break
            t -= 1
        else:
            count -= 1
            break
    T += 1
print('{}次实验成功率：{:f}'.format(times, count/times))
