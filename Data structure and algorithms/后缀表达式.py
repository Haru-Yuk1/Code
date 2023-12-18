def suffix(s):
    stack=[]
    for i in s:
        if i!='+' and i!='-' and i!='/' and i!='*' and i!='#':
            stack.append(i)
        elif i=='+':
            a=int(stack.pop())
            if not stack:
                print(f'Expression Error: {a}')
                return 
            b=int(stack.pop())
            stack.append(b+a)
        elif i=='-':
            a=int(stack.pop())
            if not stack:
                print(f'Expression Error: {a}')
                return 
            b=int(stack.pop())
            stack.append(b-a)
        elif i=='*':
            a=int(stack.pop())
            if not stack:
                print(f'Expression Error: {a}')
                return 
            b=int(stack.pop())
            stack.append(b*a)
        elif i=='/':
            a=int(stack.pop())
            if not stack:
                print(f'Expression Error: {a}')
                return 
            b=int(stack.pop())
            if a==0:
                print(f'Error: {b}/{a}')
                return 
            stack.append(b//a)
        elif i=='#':
            c=stack.pop()
            if not stack:
                print(c)
            if stack:
                print(f'Expression Error: {c}')

s=list(map(str,input().split()))
suffix(s)