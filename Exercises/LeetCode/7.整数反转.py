x=int(input())
if x<0:
    x=int(str(x)[:0:-1])
    if x<=2**31:
        print(-x)
else:
    x=int(str(x)[::-1])
    if x<=2**31-1:
        print(x)