set1={1,2,3,"asd","A"}
for i in set1:
    x=type(i)
    if x==int:
        set1.discard(i)
print(set1)
