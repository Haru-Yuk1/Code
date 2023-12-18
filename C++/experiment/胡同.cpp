#include <iostream>
#include <stack>
using namespace std;

bool check(int n, int in[], int out[]) {
    stack<int> s; // 用栈模拟死胡同
    int i = 0, j = 0; // i指向进入序列，j指向出去序列
    while (i < n) { // 遍历进入序列
        s.push(in[i]); // 把当前汽车压入栈中
        i++; // 指向下一辆汽车
        while (!s.empty() && s.top() == out[j]) { // 如果栈顶汽车和出去序列匹配
            s.pop(); // 弹出栈顶汽车
            j++; // 指向下一辆汽车
        }
    }
    return s.empty(); // 如果栈为空，说明所有汽车都能倒出去，否则不能
}

int main() {
    int T; // 测试数据的组数
    cin >> T;
    while (T--) {
        int n; // 汽车数
        cin >> n;
        int in[n], out[n]; // 进入序列和出去序列
        for (int i = 0; i < n; i++) cin >> in[i]; // 输入进入序列
        for (int i = 0; i < n; i++) cin >> out[i]; // 输入出去序列
        if (check(n, in, out)) { // 调用check函数判断能否倒出去
            cout << "Yes" << endl; // 输出Yes
        } else {
            cout << "No" << endl; // 输出No
        }
    }
    return 0;
}


