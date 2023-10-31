text=open("D:/Document/cs/python/1/data.txt")
str1=text.read()
str2=""
list1=list()
n=0
for i in range(len(str1)):
    if(str1[i]>='0' and str1[i]<='9'):
        str2+=str(i)
    else :
        if(str1[i-1]>='0' and str1[i-1]<='9'):
            list1.append(str2)
            str2=""




