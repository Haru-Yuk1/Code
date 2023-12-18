n = int(input())

# 上半部分
for i in range(1, n + 1):
    spaces = " " * (n - i)
    stars = "*" * (2 * i - 1)
    print(spaces + stars+spaces)

# 下半部分
for i in range(n - 1, 0, -1):
    spaces = " " * (n - i)
    stars = "*" * (2 * i - 1)
    print(spaces + stars+spaces)
