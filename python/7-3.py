# T=int(input())
# for i in range(T):
#     x,y=map(int,input().split())
#     for j in range(x):



# 定义一个函数，计算一个格子周围的地雷数
def count_mines(grid, i, j):
    # 获取网格的行数和列数
    rows = len(grid)
    cols = len(grid[0])
    # 初始化地雷数为0
    mines = 0
    # 遍历该格子的上下左右以及对角线的相邻格子
    for x in range(i-1, i+2):
        for y in range(j-1, j+2):
            # 如果坐标合法且不是自身，且该格子有地雷，地雷数加一
            if 0 <= x < rows and 0 <= y < cols and (x, y) != (i, j) and grid[x][y] == '*':
                mines += 1
    # 返回地雷数
    return mines

# 定义一个函数，打印输出结果
def print_output(grid):
    # 获取网格的行数和列数
    rows = len(grid)
    cols = len(grid[0])
    # 遍历每个格子
    for i in range(rows):
        for j in range(cols):
            # 如果该格子有地雷，直接输出*
            if grid[i][j] == '*':
                print('*', end='')
            # 否则，输出该格子周围的地雷数
            else:
                print(count_mines(grid, i, j), end='')
        # 换行
        print()

# 输入测试数据的组数
T = int(input())
# 遍历每组测试数据
for t in range(T):
    # 输入行数和列数
    x, y = map(int, input().split())
    # 初始化一个空网格
    grid = []
    # 输入每行的字符，添加到网格中
    for i in range(x):
        row = input()
        grid.append(row)
    # 如果不是第一组测试数据，输出一个空行作为分隔符
    if t > 0:
        print()
    # 调用打印输出结果的函数
    print_output(grid)
