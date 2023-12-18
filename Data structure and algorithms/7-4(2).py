# 定义一个函数，用字典序法求给定列表的下一个排列
def next_permutation(nums):
  # 从后往前找到第一个升序对(i, j)，即nums[i] < nums[j]
  i = len(nums) - 2
  while i >= 0 and nums[i] >= nums[i + 1]:
    i -= 1
  # 如果找到了升序对，说明还有下一个排列
  if i >= 0:
    # 从后往前找到第一个大于nums[i]的数nums[k]
    k = len(nums) - 1
    while k >= 0 and nums[k] <= nums[i]:
      k -= 1
    # 交换nums[i]和nums[k]
    nums[i], nums[k] = nums[k], nums[i]
    # 反转nums[i+1:]，使其升序排列
    nums[i + 1:] = reversed(nums[i + 1:])
    # 返回True表示成功找到下一个排列
    return True
  # 否则，说明已经是最后一个排列，没有下一个排列
  else:
    # 返回False表示没有找到下一个排列
    return False

# 输入N和N个正整数，存入列表nums
N = int(input())
nums = list(map(int, input().split()))

# 输出第一个排列，即原始列表
print(*nums)

# 循环调用next_permutation函数，直到返回False为止
while next_permutation(nums):
  # 输出下一个排列
  print(*nums)
