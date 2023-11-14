class Box:
    def __init__(self,width,height,deepth):
        self.width =width
        self.height=height
        self.deepth=deepth
    def getVolume(self):
        return self.width*self.height*self.deepth

#测试
C=Box(3,4,5)
print(C.getVolume())
            