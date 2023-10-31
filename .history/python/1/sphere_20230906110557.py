import math 
def v(r):
    return 4/3*math.pi*math.pow(r,3)

def s(r):
    return 4*math.pi*math.pow(r,2)

if __name__=='__main__:
    print(v(4))
    print(s(4))