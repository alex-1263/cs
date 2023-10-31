def feib():
    x,y=0,1
    while True:
        yield x
        x,y=y,x+y

x=feib()
for i in range(5):
    print(x)