#include <iostream>
#include <string>
using namespace std;

// 定义一个常量，表示年兽的字符串
const string NIAN = "Nian";

// 定义一个函数，根据输入的字符串，找到所有年兽的个数和位置
pair<int, int> find_nian(string input) {
    pair<int, int> result; // 定义一个结果变量，存储年兽的个数和位置
    result.first = 0; // 初始化年兽的个数为零
    result.second = -1; // 初始化年兽的位置为-1
    for (int i = 0; i < input.size(); i++) { // 遍历输入字符串的每个字符
        if (input.substr(i, 4) == NIAN) { // 如果从当前位置开始的四个字符等于年兽的字符串
            result.first++; // 年兽的个数加一
            if (result.second == -1) { // 如果还没有找到第一个年兽的位置
                result.second = i; // 记录当前位置为第一个年兽的位置
            }
        }
    }
    return result; // 返回结果变量
}

// 主函数
int main() {
    string input; // 定义一个字符串变量，存储输入的字符串
    getline(cin, input); // 输入一行字符串
    pair<int, int> output = find_nian(input); // 调用找年兽的函数，得到输出的结果
    cout << output.first << " " << output.second << endl; // 输出年兽的个数和位置
    return 0; // 结束程序
}
