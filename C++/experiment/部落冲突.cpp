// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 定义一个结构体表示绿洲
// struct Oasis {
//     int x, y, w, h; // 左上角坐标，宽度，高度
//     int area; // 面积
//     Oasis(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
//         area = w * h; // 计算面积
//     }
// };

// // 定义一个函数，根据给定的界线 x，计算部落 A 和 B 的绿洲面积之差
// int diff(vector<Oasis>& oases, int x) {
//     int a = 0, b = 0; // 部落 A 和 B 的绿洲面积
//     for (auto& o : oases) {
//         if (o.x + o.w <= x) { // 绿洲完全在界线左边，归属于部落 A
//             a += o.area;
//         } else if (o.x >= x) { // 绿洲完全在界线右边，归属于部落 B
//             b += o.area;
//         } else { // 绿洲跨越界线，需要分割
//             int left = x - o.x; // 界线左边的绿洲宽度
//             int right = o.w - left; // 界线右边的绿洲宽度
//             a += left * o.h; // 界线左边的绿洲面积
//             b += right * o.h; // 界线右边的绿洲面积
//         }
//     }
//     return a - b; // 返回部落 A 和 B 的绿洲面积之差
// }

// // 定义一个函数，使用二分搜索找到最优的界线 x
// int find_x(vector<Oasis>& oases) {
//     int l = 0, r = 1000000; // 界线的范围
//     while (l < r) {
//         int mid = l + (r - l) / 2; // 中点
//         int d = diff(oases, mid); // 计算部落 A 和 B 的绿洲面积之差
//         if (d == 0) { // 如果两部分的绿洲面积相等，直接返回中点
//             return mid;
//         } else if (d > 0) { // 如果部落 A 的绿洲面积大于部落 B 的绿洲面积，需要向右移动界线
//             l = mid + 1;
//         } else { // 如果部落 A 的绿洲面积小于部落 B 的绿洲面积，需要向左移动界线
//             r = mid;
//         }
//     }
//     return l; // 返回最优的界线 x
// }

// int main() {
//     int n; // 绿洲的个数
//     cin >> n;
//     vector<Oasis> oases; // 存储所有的绿洲
//     for (int i = 0; i < n; i++) {
//         int x, y, w, h; // 输入绿洲的左上角坐标，宽度，高度
//         cin >> x >> y >> w >> h;
//         oases.emplace_back(x, y, w, h); // 创建一个绿洲对象并加入到数组中
//     }
//     int x = find_x(oases); // 找到最优的界线 x
//     cout << x << endl; // 输出界线 x
//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

struct Oasis {
    int x, y, w, h;
};

int findPartition(vector<Oasis>& oasisList) {
    int totalArea = 0;
    for (const auto& oasis : oasisList) {
        totalArea += oasis.w * oasis.h;
    }

    int halfArea = totalArea / 2;
    int currentArea = 0;
    int partitionLine = 0;

    for (const auto& oasis : oasisList) {
        currentArea += oasis.w * oasis.h;
        if (currentArea >= halfArea) {
            partitionLine = oasis.x + oasis.w / 2;
            break;
        }
    }

    return partitionLine;
}

int main() {
    int n;
    cin >> n;

    vector<Oasis> oasisList(n);

    for (int i = 0; i < n; ++i) {
        cin >> oasisList[i].x >> oasisList[i].y >> oasisList[i].w >> oasisList[i].h;
    }

    int partitionLine = findPartition(oasisList);

    cout << partitionLine << endl;

    return 0;
}
