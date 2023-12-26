# 输入绿洲的个数
n = int(input())
# 存储所有绿洲的信息，每个元素是一个列表 [x, y, w, h]
oases = []
# 存储所有绿洲的左上角和右下角坐标，每个元素是一个列表 [x, y, type, h]
# type 为 0 表示左上角，为 1 表示右下角
points = []
# 存储所有绿洲的总面积
total_area = 0
# 输入每个绿洲的信息
for i in range(n):
    x, y, w, h = map(int, input().split())
    oases.append([x, y, w, h])
    points.append([x, y, 0, h])
    points.append([x + w, y + h, 1, h])
    total_area += w * h
# 按照 x 坐标从小到大排序
points.sort()
# 初始化部落 A 的绿洲面积为 0
area_A = 0
# 初始化部落 B 的绿洲面积为所有绿洲的总面积
area_B = total_area
# 初始化答案为 -1
ans = -1
# 初始化高度集合为空
H = set()
# 初始化前一个坐标点的 x 坐标为 0
prev_x = 0
# 遍历所有坐标点
for p in points:
    # 如果是左上角坐标，将高度加入高度集合，更新部落 A 的绿洲面积
    if p[2] == 0:
        H.add(p[3])
        area_A += p[3] * (p[0] - prev_x)
    # 如果是右下角坐标，将高度从高度集合中删除，更新部落 B 的绿洲面积
    else:
        H.remove(p[3])
        area_B -= p[3] * (p[0] - prev_x)
    # 更新前一个坐标点的 x 坐标
    prev_x = p[0]
    # 如果部落 A 的绿洲面积不小于部落 B 的绿洲面积，更新答案，结束遍历
    if area_A >= area_B:
        ans = p[0]
        break
# 输出答案
print(ans)
