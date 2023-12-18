def inversion(arr):
    if arr is None or len(arr)<2:
        return 
    merge_sort(arr,0,len(arr)-1)
def merge(arr, left, mid, right):
    # 创建一个辅助数组
    temp = []
    # 初始化两个指针，分别指向两个子数组的起始位置
    i = left
    j = mid + 1
    # 比较两个子数组的元素，并将较小的元素放入辅助数组中
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:#当左边一个大时，说明从左边那个开始右边的都大，都是逆序对
            for k in range(i,mid+1): #由于sort 会导致比较的那一个会merge到temp中，所以必须用for来打印
                print(f"<{arr[k]},{arr[j]}>")
            temp.append(arr[j])
            j += 1        
    # 将剩余的元素放入辅助数组中
    while i <= mid:
        temp.append(arr[i])
        i += 1
    while j <= right:
        temp.append(arr[j])
        j += 1
    # 将辅助数组中的元素复制回原数组中
    for i in range(left, right + 1):
        arr[i] = temp[i - left]
# 定义一个归并排序函数，用于递归地对数组进行分解和合并
def merge_sort(arr, left, right):
    if left== right:
        return    
    # 计算中间位置
    mid = left+((right-left)>>1)
    merge_sort(arr, left, mid)
    merge_sort(arr, mid + 1, right)
    merge(arr, left, mid, right)


arr = [2,3,8,6,1]
inversion(arr)



# # 定义一个打印逆序对的函数，参数是一个数组
# def print_reverse_pairs(arr):
#     # 如果数组为空或只有一个元素，直接返回
#     if arr == None or len(arr) < 2:
#         return
#     # 调用归并排序的函数，传入数组，起始位置和终止位置
#     merge_sort(arr, 0, len(arr) - 1)

# # 定义一个归并排序的函数，参数是一个数组，起始位置和终止位置
# def merge_sort(arr, left, right):
#     # 如果起始位置小于终止位置，说明还可以继续分解
#     if left < right:
#         # 计算中间位置
#         mid = left + ((right - left) >> 1)
#         # 对左半部分进行归并排序
#         merge_sort(arr, left, mid)
#         # 对右半部分进行归并排序
#         merge_sort(arr, mid + 1, right)
#         # 将两个有序的子数组合并，并打印逆序对
#         merge_and_print(arr, left, mid, right)

# # 定义一个合并并打印逆序对的函数，参数是一个数组，起始位置，中间位置和终止位置
# def merge_and_print(arr, left, mid, right):
#     # 创建一个辅助数组
#     temp = []
#     # 初始化两个指针，分别指向两个子数组的起始位置
#     i = left
#     j = mid + 1
#     # 比较两个子数组的元素，并将较小的元素放入辅助数组中
#     while i <= mid and j <= right:
#         if arr[i] <= arr[j]:
#             temp.append(arr[i])
#             i += 1
#         else:
#             temp.append(arr[j])
#             j += 1
#             # 如果右边的元素小于左边的元素，说明存在逆序对，打印出来
#             for k in range(i, mid + 1):
#                 print((arr[k], arr[j - 1]))
#     # 将剩余的元素放入辅助数组中
#     while i <= mid:
#         temp.append(arr[i])
#         i += 1
#     while j <= right:
#         temp.append(arr[j])
#         j += 1
#     # 将辅助数组中的元素复制回原数组中
#     for i in range(left, right + 1):
#         arr[i] = temp[i - left]

# # 测试代码        
# arr = [2,3,8,6,1]
# print("原始数组：", arr)
# print("逆序对：")
# print_reverse_pairs(arr)
