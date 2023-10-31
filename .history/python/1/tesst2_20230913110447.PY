total = 0
n=1
while n< 100:
    total += n
    n+=2
print("100以内的奇数和为：",total)

list1 = list(range(1,100,2))
for ans in list1:
    ans+=list1
print(ans)