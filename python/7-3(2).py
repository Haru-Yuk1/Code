T=int(input())

for t in range(T):
    x,y=map(int,input().split())
    grid=[]
    for i in range(x):
        row=input()
        grid.append(row)
    if t>0 :
        print()  
    
    for i in range(x):
        for j in range(y):
            if grid[i][j]=="*":
                print('*',end='')
            else:
                mines=0
                for m in range(i-1,i+2):
                    for n in range(j-1,j+2):
                        if  0<=m<x and 0<=n<y and (m,n)!=(i,j) and grid[m][n]=="*":
                            mines+=1
                print(mines,end='')
        print()