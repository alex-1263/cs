f=open("try.py","+r",encoding="utf8")
print(f.closed) # output: False3.
print(f.mode)# output: r4.
print(f.name)# output:step/test.txt 
f.close()