x=input()
if x==x[len(x)-1::-1]:
    print(f'{x}是回文。')
else:
    print(f'{x}不是回文。')
