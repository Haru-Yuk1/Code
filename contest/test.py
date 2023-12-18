# 读取输入
R, C = map(int, input().split()) # 行数和列数
matrix = [] # 矩阵
for _ in range(R):
    matrix.append(input()) # 每一行的字母
print(matrix)
for i in range(C):
    rows=matrix[i]
# 定义一个函数，判断两个字符串是否相等
def equal(s1, s2):
    return s1 == s2

# 定义一个函数，判断矩阵中是否有两列相等
def has_equal_columns(matrix):
    for i in range(C): # 遍历每一列
        for j in range(R): # 遍历其他列
            # 如果两列相等，返回True
            if equal(matrix[i], matrix[j]):
                return True
    # 如果没有两列相等，返回False
    return False

# # 定义一个变量，记录可以删除的最大行数
# max_rows = 0

# # 从上到下遍历每一行
# for i in range(R):
#     # 删除当前行，得到一个新的矩阵
#     new_matrix = matrix[i + 1:]
#     # 如果新的矩阵中没有两列相等，更新最大行数
#     if not has_equal_columns(new_matrix):
#         max_rows = i + 1

# # 输出最大行数
# print(max_rows)
