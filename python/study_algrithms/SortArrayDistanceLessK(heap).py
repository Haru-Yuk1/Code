import heapq

# 堆排序算法和python针对几乎有序的数组进行排序
def heapSort(arr, k):
    # 创建一个大小为k+1的最小堆
    minHeap = []
    # 将数组中的前k+1个元素加入堆中
    i=0
    for i in range(min(k + 1, len(arr))):
        heapq.heappush(minHeap, arr[i])
    # 创建一个index 用来记录更新数组时的位置
    index=0
    # 从第k+2个元素开始遍历数组
    for i in range(k+1,len(arr)):
        # 将当前元素加入堆中
        heapq.heappush(minHeap, arr[i])
        # 从堆中弹出最小的元素，并将其放入数组中
        arr[index]=heapq.heappop(minHeap)
        index+=1
    # 将堆中剩余的元素依次放入结果数组中
    while minHeap:
        arr[index]=heapq.heappop(minHeap)
        index+=1
    # 将结果数组复制到原数组中
    

# 测试代码
if __name__ == "__main__":
    # 创建一个几乎有序的数组
    arr = [2, 1, 4, 3, 6, 5, 8, 7, 10, 9]
    # 打印原数组
    print("Original array:", arr)
    # 设置k为2
    k = 2
    # 调用堆排序算法和python针对几乎有序的数组进行排序
    heapSort(arr, k)
    # 打印排序后的数组
    print("Sorted array:", arr)




# 下面是添加了一个结果数组res作为辅助的方法


# import heapq

# # 堆排序算法和python针对几乎有序的数组进行排序
# def heapSort(arr, k):
#     # 创建一个大小为k+1的最小堆
#     minHeap = []
#     # 将数组中的前k+1个元素加入堆中
#     for i in range(min(k + 1, len(arr))):
#         heapq.heappush(minHeap, arr[i])
#     # 创建一个结果数组
#     res = []
#     # 从第k+2个元素开始遍历数组
#     for i in range(k + 1, len(arr)):
#         # 从堆中弹出最小的元素，并将其放入结果数组中
#         res.append(heapq.heappop(minHeap))
#         # 将当前元素加入堆中
#         heapq.heappush(minHeap, arr[i])
#     # 将堆中剩余的元素依次放入结果数组中
#     while minHeap:
#         res.append(heapq.heappop(minHeap))
#     # 将结果数组复制到原数组中
#     arr[:] = res

# # 测试代码
# if __name__ == "__main__":
#     # 创建一个几乎有序的数组
#     arr = [2, 1, 4, 3, 6, 5, 8, 7, 10, 9]
#     # 打印原数组
#     print("Original array:", arr)
#     # 设置k为2
#     k = 2
#     # 调用堆排序算法和python针对几乎有序的数组进行排序
#     heapSort(arr, k)
#     # 打印排序后的数组
#     print("Sorted array:", arr)
