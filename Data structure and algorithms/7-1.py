# 读入两个正整数A和B
A, B = map(int, input().split())

# 定义一个函数，用辗转相除法求最大公约数
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# 定义一个函数，用最大公约数求最小公倍数
def lcm(a, b):
    return a * b // gcd(a, b)

# 输出最大公约数和最小公倍数，用逗号分隔
print(gcd(A, B), lcm(A, B), sep=',')



#另一种写法

# # 读入两个正整数A和B
# A, B = map(int, input().split())
# # 用辗转相除法求最大公约数
# a = A # 用a和b来保存A和B的值，避免修改原始输入
# b = B
# while b != 0: # 当b不为0时，重复以下步骤
#     r = a % b # 计算a除以b的余数r
#     a = b # 将b赋值给a
#     b = r # 将r赋值给b

# # 此时，a就是最大公约数
# gcd = a

# # 用最大公约数求最小公倍数
# lcm = A * B // gcd

# # 输出最大公约数和最小公倍数，用逗号分隔
# print(gcd, lcm, sep=',')
