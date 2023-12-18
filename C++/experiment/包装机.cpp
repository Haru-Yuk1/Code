#include <iostream>
#include <queue>
#include<stack>
using namespace std;

int main() {
    int N, M, S; // 轨道数，物品数，筐容量
    cin >> N >> M >> S;
    queue<char> track[N]; // 用队列模拟每条轨道
    stack<char> basket; // 用队列模拟筐
    string line; // 用字符串存储每条轨道的物品
    for (int i = 0; i < N; i++) { // 输入每条轨道的物品
        cin >> line;
        for (int j = 0; j < M; j++) {
            track[i].push(line[j]); // 把每个物品压入对应的队列
        }
    }
    int button; // 按钮编号
    string output = ""; // 输出的字符串
    while (cin >> button) { // 输入按钮编号，直到-1结束
        if (button == -1) break; // 结束输入
        if (button == 0) { // 如果按下0号按钮
            if (!basket.empty()) { // 如果筐不为空
                output += basket.top(); // 把筐顶部的物品加入输出字符串
    
                basket.pop(); // 弹出筐顶部的物品
            }
        } else { // 如果按下其他按钮
            int i = button - 1; // 对应的轨道编号
            if (!track[i].empty()) { // 如果轨道不为空
                if (basket.size() == S) { // 如果筐已满
                    output += basket.top(); // 把筐顶部的物品加入输出字符串
                    basket.pop(); // 弹出筐顶部的物品
                }
                basket.push(track[i].front()); // 把轨道尾部的物品压入筐中
                track[i].pop(); // 弹出轨道尾部的物品
            }
        }
    }
    cout << output << endl; // 输出结果字符串
    return 0;
}
