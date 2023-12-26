def insertionSort(arr):
    for i in range(len(arr)):
        for j in range(i,0,-1):
            if arr[j-1]>arr[j]:
                arr[j],arr[j-1]=arr[j-1],arr[j]
        if i!=0:    
            for j in arr:
                if j==arr[len(arr)-1]:
                    print(f'{j}')
                else:
                    print(f'{j}',end=' ')
    return arr

n=int(input())
arr=list(map(int,input().split()))
insertionSort(arr)