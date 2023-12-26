def selectionSort(arr):
    if arr==[] or len(arr)<2:
        return arr
    for i in range(len(arr)-1):# 0~N-1
        minIndex=i
        for j in range(i+1,len(arr)):
            minIndex=j if arr[j]<arr[minIndex] else minIndex
        arr[i],arr[minIndex]=arr[minIndex],arr[i]
    return arr

a1=selectionSort([4,2,3,1,5,7,9,8])
a2=selectionSort([1,3,4])
print(a1)
print(a2)
