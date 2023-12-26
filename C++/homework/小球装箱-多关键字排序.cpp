// 引入头文件
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个结构体，表示小球的属性
struct Ball {
    int num; // 小球上的数字
    int color; // 小球的颜色，0为红色，1为绿色
};

// 定义一个比较函数，用于排序小球
bool compare(Ball a, Ball b) {
    // 如果小球上的数字不同，按照数字从大到小排序
    if (a.num != b.num) return a.num > b.num;
    // 如果小球上的数字相同，按照颜色排序，红色优先于绿色
    return a.color < b.color;
}

int main() {
    int n; // 小球的总数
    cin >> n; // 输入小球的总数
    vector<Ball> balls(n); // 创建一个大小为n的向量，存储小球
    for (int i = 0; i < n; i++) {
        cin >> balls[i].num >> balls[i].color; // 输入每个小球的数字和颜色
    }
    sort(balls.begin(), balls.end(), compare); // 对小球进行排序
    int ar = 0, ag = 0, br = 0, bg = 0; // 初始化四个变量，分别表示A、B两个球箱中红色和绿色小球的数量
    for (int i = 0; i < n / 2; i++) { // 遍历前一半的小球，放入A箱中
        if (balls[i].color == 0) ar++; // 如果是红色小球，A箱中红色小球数量加一
        else ag++; // 如果是绿色小球，A箱中绿色小球数量加一
    }
    for (int i = n / 2; i < n; i++) { // 遍历后一半的小球，放入B箱中
        if (balls[i].color == 0) br++; // 如果是红色小球，B箱中红色小球数量加一
        else bg++; // 如果是绿色小球，B箱中绿色小球数量加一
    }
    cout << ar << " " << ag << endl; // 输出A箱中红色和绿色小球的数量
    cout << br << " " << bg << endl; // 输出B箱中红色和绿色小球的数量
    return 0;
}
