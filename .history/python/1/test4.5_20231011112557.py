set1={1,2,3,"asd","A"}
set2=set()
for i in set1:
    x=type(i)
    if x==int:
        set2.add(i)
print(set1)
