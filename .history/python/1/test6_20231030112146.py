def feib():
    x,y=0,1
    while True:
        yield x
        x,y=y,x+y

y=feib()
for i in range(10):
    print(y)