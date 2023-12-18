def fullpermutation(list):
        if list == None:
            return None
        if len(list) == 1:    # 从list[1]处开始递归的
            return [list]
        res = []
        left = list[0]
        right = fullpermutation(list[1:]) #递归
        for i in right:
            for j in range(len(i)+1):
                res.append(i[:j]+[left]+i[j:])

        return res
# 输入
N = int(input())
nums = list(map(int,input().split()))  
# 对数组全排列
nums=fullpermutation(nums)
# 去重      
newnums=[]
for i in nums:
      if i not in newnums:
            newnums.append(i)
# 字典序排列
sorted(newnums)
for i in newnums:
    for j in i:
        print(j,end=' ')
    print()