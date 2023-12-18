// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 定义一个结构体，表示一个绿洲
// struct Oasis {
//     int x, y, w, h; // 左上角坐标，宽度，高度
//     int area; // 面积
//     Oasis(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
//         area = w * h; // 计算面积
//     }
// };

// // 定义一个函数，计算给定一个分界线 x，两部分的绿洲面积差的绝对值
// int diff(vector<Oasis>& oases, int x) {
//     int left = 0, right = 0; // 左右部分的绿洲面积
//     for (auto& o : oases) { // 遍历所有绿洲
//         if (o.x + o.w <= x) { // 如果绿洲完全在分界线左边
//             left += o.area; // 加到左边的面积
//         } else if (o.x >= x) { // 如果绿洲完全在分界线右边
//             right += o.area; // 加到右边的面积
//         } else { // 如果绿洲跨越分界线
//             left += (x - o.x) * o.h; // 计算左边部分的面积
//             right += (o.x + o.w - x) * o.h; // 计算右边部分的面积
//         }
//     }
//     return abs(left - right); // 返回两部分的面积差的绝对值
// }

// int main() {
//     int n; // 绿洲的个数
//     cin >> n;
//     vector<Oasis> oases; // 存储所有绿洲
//     int min_x = 1e6, max_x = 0; // 记录所有绿洲的最小和最大的 x 坐标
//     for (int i = 0; i < n; i++) { // 输入 n 个绿洲
//         int x, y, w, h; // 绿洲的左上角坐标，宽度，高度
//         cin >> x >> y >> w >> h;
//         oases.emplace_back(x, y, w, h); // 创建一个绿洲对象，加入到数组中
//         min_x = min(min_x, x); // 更新最小的 x 坐标
//         max_x = max(max_x, x + w); // 更新最大的 x 坐标
//     }
//     int ans = -1; // 存储最终的答案
//     int min_diff = 1e9; // 存储最小的面积差
//     for (int x = min_x; x <= max_x; x++) { // 枚举所有可能的分界线 x
//         int d = diff(oases, x); // 计算当前分界线的面积差
//         if (d < min_diff) { // 如果当前分界线的面积差更小
//             min_diff = d; // 更新最小的面积差
//             ans = x; // 更新最终的答案
//         }
//     }
//     cout << ans << endl; // 输出最终的答案
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个结构体，表示一个绿洲
struct Oasis {
    int x, y, w, h; // 左上角坐标，宽度，高度
    int area; // 面积
    Oasis(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
        area = w * h; // 计算面积
    }
};

// 定义一个函数，判断一个绿洲是否在 x 左边
bool isLeft(Oasis o, int x) {
    return o.x + o.w <= x;
}

// 定义一个函数，判断一个绿洲是否在 x 右边
bool isRight(Oasis o, int x) {
    return o.x >= x;
}

// 定义一个函数，计算一个绿洲数组的总面积
int sumArea(vector<Oasis> &oases) {
    int sum = 0;
    for (auto o : oases) {
        sum += o.area;
    }
    return sum;
}

// 定义一个函数，根据给定的 x，将绿洲分成两部分，返回两部分的面积差的绝对值
int splitOases(vector<Oasis> &oases, int x) {
    vector<Oasis> left, right; // 存储左右两部分的绿洲
    for (auto o : oases) {
        if (isLeft(o, x)) { // 如果绿洲在 x 左边，加入左部分
            left.push_back(o);
        } else if (isRight(o, x)) { // 如果绿洲在 x 右边，加入右部分
            right.push_back(o);
        } else { // 如果绿洲跨越 x，分割成两个绿洲，分别加入左右部分
            int left_w = x - o.x; // 左边绿洲的宽度
            int right_w = o.w - left_w; // 右边绿洲的宽度
            left.push_back(Oasis(o.x, o.y, left_w, o.h)); // 创建左边绿洲
            right.push_back(Oasis(x, o.y, right_w, o.h)); // 创建右边绿洲
        }
    }
    // 计算左右两部分的面积
    int left_area = sumArea(left);
    int right_area = sumArea(right);
    // 返回面积差的绝对值
    return abs(left_area - right_area);
}

int main() {
    int n; // 绿洲的个数
    cin >> n;
    vector<Oasis> oases; // 存储所有的绿洲
    int min_x = 1e6, max_x = 0; // 记录最小和最大的 x 坐标
    for (int i = 0; i < n; i++) {
        int x, y, w, h; // 输入绿洲的信息
        cin >> x >> y >> w >> h;
        oases.push_back(Oasis(x, y, w, h)); // 创建一个绿洲并加入数组
        min_x = min(min_x, x); // 更新最小的 x 坐标
        max_x = max(max_x, x + w); // 更新最大的 x 坐标
    }
    int ans = -1; // 存储最终的答案
    int min_diff = 1e6; // 存储最小的面积差
    // 遍历所有可能的 x 坐标，从最小的 x + 1 到最大的 x - 1
    for (int x = min_x + 1; x < max_x; x++) {
        // 计算当前的 x 坐标下的面积差
        int diff = splitOases(oases, x);
        // 如果面积差小于当前的最小值，更新答案和最小值
        if (diff < min_diff) {
            ans = x;
            min_diff = diff;
        }
    }
    // 输出答案
    cout << ans << endl;
    return 0;
}
