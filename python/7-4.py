# N=int(input())
# num=list(map(int,input().split()))

# for i in range(len(num)):

# # 定义一个函数，用于交换列表中的两个元素
# def swap(lst, i, j):
#     # 保存第i个元素的值
#     temp = lst[i]
#     # 将第j个元素的值赋给第i个元素
#     lst[i] = lst[j]
#     # 将保存的第i个元素的值赋给第j个元素
#     lst[j] = temp

# # 定义一个函数，用于生成全排列
# def permute(lst, start, end):
#     # 如果起始位置等于结束位置，说明已经到达最后一个元素，打印当前列表
#     if start == end:
#         print(*lst)
#     # 否则，遍历从起始位置到结束位置的所有元素
#     else:
#         for i in range(start, end + 1):
#             # 将当前元素与起始位置的元素交换，相当于固定当前元素为第一个位置
#             swap(lst, start, i)
#             # 递归地对剩余的元素进行全排列
#             permute(lst, start + 1, end)
#             # 恢复原来的列表，相当于回溯
#             swap(lst, start, i)

# # 输入整数N
# N = int(input())
# # 输入N个数字，转换为整数列表
# lst = list(map(int, input().split()))
# # 调用全排列函数，传入列表，起始位置和结束位置
# permute(lst, 0, N - 1)




# 定义一个函数，用递归的方法生成全排列
def permute(nums, start, end, result):
    # 如果起始位置等于结束位置，说明已经到达最后一个元素，将当前排列加入结果列表
    if start == end:
        result.append(nums[:]) # 注意要用nums[:]而不是nums，因为nums[:]是nums的一个拷贝，而nums是引用
    else:
        # 遍历从起始位置到结束位置的所有元素
        for i in range(start, end + 1):
            # 将当前元素和起始元素交换位置
            nums[start], nums[i] = nums[i], nums[start]
            # 递归地对剩余的元素进行全排列
            permute(nums, start + 1, end, result)
            # 恢复原来的顺序，以便进行下一次交换
            nums[start], nums[i] = nums[i], nums[start]

# 读取输入
n = int(input()) # 读取整数N
nums = list(map(int, input().split())) # 读取N个数字，转换为整数列表



# 创建一个空列表，用于存储结果
result = []

# 调用函数，生成全排列
permute(nums, 0, len(nums) - 1, result)

# 按字典序排序结果列表
newresult=[]
for i in result:
    if i not in newresult:
        newresult.append(i)
newresult.sort()
for i in newresult:
    for j in i:
        print(j,end=' ')
    print()

# # 输入N和数字列表
# N = int(input())
# nums = input().split()

# # 生成所有排列
# perms = list(set(itertools.permutations(nums)))

# # 按字典序排序
# perms.sort()

# # 输出每个排列
# for perm in perms:
#     print(' '.join(perm))
