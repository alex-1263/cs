import catch
hl=0
w=0
chance=0
catch.csh()
while True:
    catch.catch()
    if(hl==w):
        print("你抓到了狐狸")
        break
    catch.jump()
    if(chance==0):
        break
