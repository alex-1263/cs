import catch
catch.csh()
while True:
    catch.catch()
    if(catch.hl==catch.w):
        print("游戏胜利，你抓到了狐狸！！！")
        break
    catch.jump()
    if(catch.chance==0):
        print("游戏失败")
        break
    print("没抓到，还有%d天"%catch.chance)
