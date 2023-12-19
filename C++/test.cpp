#include <iostream>
using namespace std;

int main() {
    int N, M, P; // 待存储的元素个数，散列表的长度，散列函数的模数
    cin >> N >> M >> P;
    int* arr = new int[M]; // 散列表
    for (int i = 0; i < M; i++) {
        arr[i] = -1; // 初始化为-1，表示空位
    }
    for (int i = 0; i < N; i++) {
        int temp; // 输入的元素
        cin >> temp;
        int index = temp % P; // 计算散列地址
        while (arr[index] != -1) { // 如果发生冲突，线性探测
            index = (index + 1) % M; // 下一个地址
        }
        arr[index] = temp; // 插入元素
    }
    int num1 = 0, num2 = 0; // 查找成功和查找失败的总查找长度
    int count1 = 0, count2 = 0; // 查找成功和查找失败的总查找次数
    for (int i = 0; i < M; i++) {
        if (arr[i] != -1) { // 如果该位置有元素
            count1++; // 查找成功次数加一
            int index = arr[i] % P; // 计算散列地址
            int len = 1; // 查找长度
            while (index != i) { // 如果不是目标位置，线性探测
                index = (index + 1) % M; // 下一个地址
                len++; // 查找长度加一
            }
            num1 += len; // 累加查找成功的总查找长度
        } else { // 如果该位置为空
            count2++; // 查找失败次数加一
            int index = i; // 当前地址
            int len = 1; // 查找长度
            while (arr[index] != -1) { // 如果不是空位，线性探测
                index = (index + 1) % M; // 下一个地址
                len++; // 查找长度加一
            }
            num2 += len; // 累加查找失败的总查找长度
        }
    }
    cout << num1 << "/" << count1 << endl; // 输出查找成功时的平均查找长度
    cout << num2 << "/" << count2 << endl; // 输出查找失败时的平均查找长度
    delete[] arr;
    return 0;
}
