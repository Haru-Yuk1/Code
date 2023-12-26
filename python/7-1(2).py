# #枚举法
# def divisor(a,b):
#     if a<b:
#         a,b=b,a
#     gcd=1
#     for i in range(2,b+1):
#         if a%i==0 and b%i==0 :
#             gcd=i   
#     return gcd

# # 读入两个正整数A和B
# A, B = map(int, input().split())

# print(divisor(A, B), (A*B)//divisor(A,B), sep=',')

# 更相减损法

# def divisor(a,b):
#     i=0
#     while a%2==0 and b%2==0:
#         a=a/2
#         b=b/2
#         i+=1
#     if a<b:
#         a,b=b,a
#     while a-b!=temp:
#         temp=b
#         c=a-b
#         a=c if c>b else b
#         b=c if c<b else b

#     while i>0:
#         c=c*2
#         i-=1
#     return c    

# # 读入两个正整数A和B
# A, B = map(int, input().split())

# print(divisor(A, B), (A*B)//divisor(A,B), sep=',')




# # 定义一个函数，求两个数的最大公约数
# def gcd(a, b):
#     # 如果两个数都是偶数，就用2约简
#     if a % 2 == 0 and b % 2 == 0:
#         return 2 * gcd(a // 2, b // 2)
#     # 如果两个数不都是偶数，就用较大的数减去较小的数
#     else:
#         if a > b:
#             return gcd(a - b, b)
#         elif a < b:
#             return gcd(a, b - a)
#         else:
#             return a
# # 输入两个正整数
# A, B = map(int, input().split())

# print(gcd(A, B), (A*B)//gcd(A,B), sep=',')


# stein 算法
# 定义一个函数，用Stein算法求两个正整数的最大公约数
def gcd_stein(a, b):
  # 如果a和b都是0，返回0
  if a == 0 and b == 0:
    return 0
  # 如果a或b是0，返回另一个数
  if a == 0 or b == 0:
    return a + b
  # 如果a和b都是偶数，返回2乘以它们除以2的最大公约数
  if a % 2 == 0 and b % 2 == 0:
    return 2 * gcd_stein(a // 2, b // 2)
  # 如果a是偶数，b是奇数，返回a除以2和b的最大公约数
  if a % 2 == 0 and b % 2 == 1:
    return gcd_stein(a // 2, b)
  # 如果a是奇数，b是偶数，返回a和b除以2的最大公约数
  if a % 2 == 1 and b % 2 == 0:
    return gcd_stein(a, b // 2)
  # 如果a和b都是奇数，返回它们差的绝对值和较小的数的最大公约数
  if a % 2 == 1 and b % 2 == 1:
    return gcd_stein(abs(a - b), min(a, b))

# 定义一个函数，用两个正整数的乘积除以它们的最大公约数求最小公倍数
def lcm(a, b):
  # 如果a或b是0，返回0
  if a == 0 or b == 0:
    return 0
  # 否则，返回a乘以b除以它们的最大公约数
  else:
    return a * b // gcd_stein(a, b)

# 输入两个正整数A和B
A, B = map(int, input().split())

# 输出它们的最大公约数和最小公倍数，用逗号分隔
print(gcd_stein(A, B), lcm(A, B), sep=',')
