list1=eval(input())
a=lambda list1:[x for x in list1 if x%2==0]
print(a)
print(list(a(list1)))