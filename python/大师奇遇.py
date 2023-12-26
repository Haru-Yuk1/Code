n=int(input())
s=list(map(int,input().split(' ')))
stack=[]
cost=0
income=0

for i in s[:-1]:
    cost+=i

for i in s:
    if not stack:
        stack.append(i)
        continue
    while stack and stack[-1]<i:
        stack.pop()
        income+=i
    stack.append(i)
if stack:
    last=s[-1]
    del s
    for i in range(len(stack)-1):
        income+=last
del stack
print(income-cost)

