set1={1,2,3,5,66,7,"asd","A",9,8,7,6}
set2=set()
list1=list()
for i in set1:
    x=type(i)
    if x==int:
        set2.add(i)
print(set2)
list1=list(set2)
print(list1)