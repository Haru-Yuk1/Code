# 堆排序是一种基于二叉堆的比较排序算法
# 二叉堆是一种满足以下性质的完全二叉树：
# 1. 每个节点的值大于或等于其左右子节点的值（最大堆）
# 2. 或者每个节点的值小于或等于其左右子节点的值（最小堆）
# 堆排序的基本思想是：
# 1. 将待排序的数组构建成一个最大堆或最小堆
# 2. 每次交换堆顶元素和堆尾元素，然后调整剩余的元素维持堆的性质
# 3. 重复这个过程，直到堆中只剩下一个元素

# 定义一个函数，用于调整指定节点及其子树为最大堆
def heapify(arr, n, i):
    # 初始化最大值的索引为当前节点
    largest = i
    # 计算左右子节点的索引
    left = 2 * i + 1
    right = 2 * i + 2
    # 如果左子节点存在且大于当前最大值，更新最大值的索引
    if left < n and arr[left] > arr[largest]:
        largest = left
    # 如果右子节点存在且大于当前最大值，更新最大值的索引
    if right < n and arr[right] > arr[largest]:
        largest = right
    # 如果最大值的索引不是当前节点，交换它们的位置，并递归调整被交换的子树
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

# 定义一个函数，用于实现堆排序
def heap_sort(arr):
    # 获取数组的长度
    n = len(arr)
    # 从最后一个非叶子节点开始，自下而上构建最大堆
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    # 从最后一个元素开始，自右而左交换堆顶元素和堆尾元素，并调整剩余的元素为最大堆
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

# 测试代码
arr = [12, 11, 13, 5, 6, 7]
print("原始数组：", arr)
heap_sort(arr)
print("排序后的数组：", arr)
