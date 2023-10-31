while True:
    try:
        n=int(input("请输入评委人数"))
        assert 2<n
        break
    except AssertionError:
        print("请输入大于2的评委人数")


while True:
    try:
        pingfeng=int(input("请输入评分："))
        assert 0<pingfeng<100
        break
    except AssertionError:
        print("请输入大于0小于100的评分")