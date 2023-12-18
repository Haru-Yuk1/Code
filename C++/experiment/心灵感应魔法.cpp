#include <iostream>
#include <vector>
#include <bitset>
#include<iomanip>
using namespace std;

int main() {
    // 输入一个整数n
    int n;
    cin >> n;
    // 创建一个大小为10的二维向量，用于存储魔法表格
    vector<vector<int>> lis(10);
    // 遍历从1到n的所有数字
    for (int i = 1; i <= n; i++) {
        // 将数字转换为二进制字符串
        string bi = bitset<10>(i).to_string();
        // 从右到左遍历二进制字符串的每一位
        for (int j = 0; j < 10; j++) {
            // 如果该位为1，则将数字加入到对应的魔法表格中
            if (bi[9 - j] == '1') {
                lis[j].push_back(i);
            }
        }
    }
    // 记录当前输出的魔法表格的编号
    int times = 1;
    // 遍历所有的魔法表格
    for (auto& i : lis) {
        // 如果魔法表格不为空，则输出它
        if (!i.empty()) {
            // 如果不是第一个魔法表格，则换行
            if (times != 1) {
                cout << endl;
            }
            // 输出魔法表格的编号
            cout << "第" << times << "个魔法数组" << endl;
            // 记录当前输出的数字个数
            int count = 0;
            // 遍历魔法表格中的每个数字
            for (auto& j : i) {
                // 输出该数字，占宽为5，右对齐
                cout << right << setw(5) << j;
                // 数字个数加一
                count++;
                // 如果数字个数为4，则换行
                if (count % 4 == 0) {
                    cout << endl;
                }
            }
            // 如果最后一行不满4个数字，则换行
            if (count % 4 != 0) {
                cout << endl;
            }
            // 魔法表格编号加一
            times++;
        } else {
            // 如果魔法表格为空，则结束循环
            break;
        }
    }
    return 0;
}
