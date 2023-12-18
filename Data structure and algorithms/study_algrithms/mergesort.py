# 定义一个合并函数，用于将两个有序的子数组合并为一个有序的数组
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
        else:
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
    # 如果左边界小于右边界，说明还可以继续分解
    if left < right:
        # 计算中间位置
        mid = left+((right-left)>>1)
        # 对左半部分进行归并排序
        merge_sort(arr, left, mid)
        # 对右半部分进行归并排序
        merge_sort(arr, mid + 1, right)
        # 将两个有序的子数组合并为一个有序的数组
        merge(arr, left, mid, right)

# 测试代码
arr = [9, 4, 6, 2, 7, 3, 8, 5]
print("原始数组：", arr)
merge_sort(arr, 0, len(arr) - 1)
print("排序后的数组：", arr)
