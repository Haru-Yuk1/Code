#include <iostream>
#include <queue>
using namespace std;

int main() {
    int M; // 操作次数
    cin >> M;
    queue<int> q; // 队列
    while (M--) {
        string op; // 操作命令
        cin >> op;
        if (op == "push") { // 向队尾插入一个数
            int x; // 要插入的数
            cin >> x;
            q.push(x); // 调用队列的push方法
        } else if (op == "pop") { // 从队头弹出一个数
            if (!q.empty()) { // 队列不为空
                q.pop(); // 调用队列的pop方法
            }
        } else if (op == "empty") { // 判断队列是否为空
            if (q.empty()) { // 队列为空
                cout << "YES" << endl; // 输出YES
            } else { // 队列不为空
                cout << "NO" << endl; // 输出NO
            }
        } else if (op == "query") { // 查询队头元素
            if (!q.empty()) { // 队列不为空
                cout << q.front() << endl; // 输出队头元素的值，调用队列的front方法
            }
        }
    }
    return 0;
}
