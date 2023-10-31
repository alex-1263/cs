import catch
catch.csh()
while True:
    catch.catch()
    if(catch.hl==catch.w):
        print("你抓到了狐狸")
        break
    catch.jump()
    if(catch.chance==0):
        break
    print("没抓到，还有%d天"%catch.chance)
