#include <iostream>
#include <vector>
using namespace std;

// 定义一个结构体，表示一个格子的信息
struct Cell {
    int height; // 高度
    bool firework; // 是否有烟花
    bool visible; // 是否可见
};

// 定义一个函数，判断一个格子是否能看到一个燃放的烟花
bool can_see(Cell cell, Cell firework, int h) {
    // 如果格子与烟花不在同一行或同一列，返回 false
    if (cell.height != firework.height && cell.firework != firework.firework) {
        return false;
    }
    // 如果格子与烟花的连线上的所有格子，要不是空格子，要不格子上的任何物体的高度小于小 C 的身高，返回 true
    if (cell.visible && cell.height < h) {
        return true;
    }
    // 否则返回 false
    return false;
}

// 定义一个函数，计算一个格子能看到的烟花的个数
int count_fireworks(Cell cell, vector<vector<Cell>> matrix, int h) {
    int count = 0; // 初始化计数器为 0
    // 遍历矩阵中的每个格子
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            // 如果该格子有烟花，且当前格子能看到该烟花，计数器加一
            if (matrix[i][j].firework && can_see(cell, matrix[i][j], h)) {
                count++;
            }
        }
    }
    // 返回计数器的值
    return count;
}

// 定义一个函数，找到所有对小 C 而言的优秀的观赏位置，并输出能看到最多的烟花的格子的坐标
void find_best_positions(vector<vector<Cell>> matrix, int h) {
    int max_fireworks = 0; // 初始化最多能看到的烟花的个数为 0
    int best_x = -1; // 初始化最佳观赏位置的横坐标为 -1
    int best_y = -1; // 初始化最佳观赏位置的纵坐标为 -1
    int best_count = 0; // 初始化优秀的观赏位置的个数为 0
    // 遍历矩阵中的每个格子
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            // 如果该格子是空的，计算该格子能看到的烟花的个数
            if (matrix[i][j].height == 0) {
                int fireworks = count_fireworks(matrix[i][j], matrix, h);
                // 如果该格子能看到三个及以上不同格子上燃放的烟花，该格子是一个优秀的观赏位置
                if (fireworks >= 3) {
                    best_count++; // 优秀的观赏位置的个数加一
                    // 如果该格子能看到的烟花的个数大于当前的最大值，更新最大值和最佳观赏位置的坐标
                    if (fireworks > max_fireworks) {
                        max_fireworks = fireworks;
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }
    }
    // 输出优秀的观赏位置的个数
    cout << best_count << endl;
    // 输出能看到最多的烟花的格子的坐标
    cout << best_x << " " << best_y << endl;
}

// 主函数
int main() {
    int n, m, h; // 输入活动场地矩阵的大小和小 C 的身高
    cin >> n >> m >> h;
    vector<vector<Cell>> matrix(n, vector<Cell>(m)); // 创建一个 n x m 的矩阵
    // 输入矩阵中的每个格子的信息
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; // 输入一个整数
            cin >> x;
            // 如果是一个正整数，表示该格子被人或建筑物占据，高度为对应的值，没有烟花，不可见
            if (x > 0) {
                matrix[i][j].height = x;
                matrix[i][j].firework = false;
                matrix[i][j].visible = false;
            }
            // 如果是一个负整数，表示该格子用于燃放烟花，没有高度，有烟花，可见
            else if (x < 0) {
                matrix[i][j].height = 0;
                matrix[i][j].firework = true;
                matrix[i][j].visible = true;
            }
            // 如果是 0，表示该格子是空格子，没有高度，没有烟花，可见
            else {
                matrix[i][j].height = 0;
                matrix[i][j].firework = false;
                matrix[i][j].visible = true;
            }
        }
    }
    // 调用函数，找到所有对小 C 而言的优秀的观赏位置，并输出能看到最多的烟花的格子的坐标
    find_best_positions(matrix, h);
    return 0;
}
