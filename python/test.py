import matplotlib.pyplot as plt
import matplotlib.patches as patches

def draw_heart():
    fig, ax = plt.subplots(figsize=(5, 5))

    # 创建一个半透明的 Heart 形状
    heart = patches.Polygon(
        [
            [1.0, 1.0],
            [4.0, 1.0],
            [2.0, 3.0],
            [5.0, 3.0],
            [8.0, 1.0],
            [6.0, 4.0],
            [6.0, 0.0],
            [7.0, 3.0],
            [5.0, 4.0],
            [2.0, 3.0],
            [7.0, 1.0],
            [5.0, 1.0],
            [5.0, 4.0],
            [5.0, 3.0],
        ],
         facecolor='none',
        edgecolor='red',
        lw=4,
    )

    ax.add_patch(heart)

    # 隐藏 axis
    ax.set_axis_off()

    # 显示绘制的图
    plt.show()

draw_heart()