set1={1,2,3,"asd","A"}
for i in set1:
    if type(i)==int:
        set1.discard(i)
print(set1)
