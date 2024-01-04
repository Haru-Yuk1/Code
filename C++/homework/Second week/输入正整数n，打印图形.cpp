#include <iostream>
using namespace std;

int main()
{
    int n; // 输入的正整数
    cin >> n; // 从标准输入读取n
    for (int i = 1; i <= n; i++) // 打印上半部分
    {
        for (int j = 1; j <= n - i; j++) // 打印空格
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) // 打印星号
        {
            cout << "*";
        }
       for (int j = 1; j <= n - i; j++) // 打印空格
        {
            cout << " ";
        }
        cout << endl; // 换行
    }
    for (int i = n - 1; i >= 1; i--) // 打印下半部分
    {
        for (int j = 1; j <= n - i; j++) // 打印空格
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) // 打印星号
        {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++) // 打印空格
        {
            cout << " ";
        }
        cout << endl; // 换行
    }
    return 0;
}
