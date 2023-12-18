def bubbleSort(arr):
    for i in range(len(arr)-1): #进行n-1轮，每轮排好一个数
        for j in range(len(arr)-1-i): #进行每轮的排序，找到最大的数排在最后
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr
test=[64, 34, 25, 12, 22, 11, 90]
sorted_arr=bubbleSort(test)
print(sorted_arr)