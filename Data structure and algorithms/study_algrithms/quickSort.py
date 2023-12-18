def quickSort(arr,L,R):
    if L>=R:
        return
    if L<R:
       p=partition(arr,L,R)
       quickSort(arr,L,p-1)
       quickSort(arr,p+1,R)
def partition(arr,L,R):
    prev=L
    cur=L+1
    key=L # 选择第一个数作为基准
    while cur<=R:
        while arr[cur]<arr[key] and cur!=prev:
            prev+=1
            arr[prev],arr[cur]=arr[cur],arr[prev]
        cur+=1
    arr[key],arr[prev]=arr[prev],arr[key]
    for i in arr:
        print(i,end=" ")
    print()
    return prev

n=int(input())
arr=list(map(int,input().split()))

quickSort(arr,0,n-1)