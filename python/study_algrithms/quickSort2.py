# import random
# def quickSort(arr,L,R):
#     if L>=R:
#         return
#     if L<R:
#        key=random.randint(L,R)
#        arr[L],arr[key]=arr[key],arr[L] #选择随机数作为基准将第一个数与随机数交换
#        p=partition(arr,L,R)
#        quickSort(arr,L,p-1)
#        quickSort(arr,p+1,R)
# def partition(arr,L,R):
#     prev=L
#     cur=L+1
#     key=L # 选择随机数作为基准
#     while cur<=R:
#         while arr[cur]<arr[key] and cur!=prev:
#             prev+=1
#             arr[prev],arr[cur]=arr[cur],arr[prev]
#         cur+=1
#     arr[key],arr[prev]=arr[prev],arr[key]
#     return prev
# arr = [2,3,8,6,1,5]
# quickSort(arr,0,len(arr)-1)
# print(arr)
def GetMidIndex(arr,L,R):
    mid=L+(R-L)>>1
    if arr[L]<arr[R]:
        if arr[mid]<arr[R]:
            return mid
        elif arr[mid]>arr[R]:
            return R
        else:
            return L
    else:
        if arr[mid]>arr[L]:
            return L
        elif arr[mid]<arr[R]:
            return R
        else:
            return mid
def quickSort(arr,L,R):
    if L>=R:
        return
    if L<R:
       key=GetMidIndex(arr,L,R)
       arr[key],arr[L]=arr[L],arr[key]
       p=partition(arr,L,R)
       quickSort(arr,L,p-1)
       quickSort(arr,p+1,R)
def partition(arr,L,R):
    prev=L
    cur=L+1
    key=L # 选择随机数作为基准
    while cur<=R:
        while arr[cur]<arr[key] and cur!=prev:
            prev+=1
            arr[prev],arr[cur]=arr[cur],arr[prev]
        cur+=1
    arr[key],arr[prev]=arr[prev],arr[key]
    return prev
arr = [2,3,8,6,1,5]
quickSort(arr,0,len(arr)-1)
print(arr)