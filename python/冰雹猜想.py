n=int(input())
count=0
while n!=1:
    print(n,end=' ')
    if n%2==0:
        n=n//2
    else:
        n=n*3+1
    count+=1
print(n)
print(f'count = {count+1}')