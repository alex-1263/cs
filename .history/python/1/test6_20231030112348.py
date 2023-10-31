def feib():
    x,y=0,1
    while True:
        yield x
        x,y=y,x+y

x=feib()
print(next(x))
print(next(x))
print(next(x))