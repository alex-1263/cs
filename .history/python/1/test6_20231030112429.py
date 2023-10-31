def feib():
    x,y=1,1
    while True:
        yield x
        x,y=y,x+y

x=feib()
for i in range(10):
    print(next(x))