# 定义一个函数，用于生成全排列
def dfs(nums, path, used, ans):
    # 如果路径长度等于数字长度，说明找到了一个排列，添加到答案中
    if len(path) == len(nums):
        ans.append(path[:])
        return
    # 遍历每个数字
    for i in range(len(nums)):
        # 如果该数字已经使用过，跳过
        if used[i]:
            continue
        # 如果该数字和前一个数字相同，并且前一个数字没有使用过，跳过
        if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
            continue
        # 将该数字添加到路径中，并标记为已使用
        path.append(nums[i])
        used[i] = True
        # 递归地继续生成排列
        dfs(nums, path, used, ans)
        # 回溯，将该数字从路径中移除，并标记为未使用
        path.pop()
        used[i] = False

# 读取输入
n = int(input())
nums = list(map(int, input().split()))
# 对数字进行排序，方便去重
nums.sort()
# 初始化路径，使用情况和答案
path = []
used = [False] * n
ans = []
# 调用函数生成全排列
dfs(nums, path, used, ans)
# 按字典序输出全排列，每个排列一行，数字间用空格分开，末尾的数字后面无空格
for perm in ans:
    print(' '.join(map(str, perm)))
