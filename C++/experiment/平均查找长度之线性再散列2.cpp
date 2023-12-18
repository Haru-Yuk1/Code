// 用C++重写的代码
// 假设P是一个素数
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int N, M, P;
int sum1 = 0, sum2 = 0;

// 散列表单元类型
struct Cell {
    int data; // 存放元素
    bool empty; // 单元状态，true表示空，false表示有合法元素
    Cell() : data(0), empty(true) {} // 默认构造函数，初始化为空单元
};

// 散列表类型
class HashTable {
private:
    int tableSize; // 表的最大长度
    vector<Cell> cells; // 存放散列单元数据的向量
public:
    // 构造函数，根据给定的表大小创建一个空的散列表
    HashTable(int size) : tableSize(size), cells(size) {}
    // 散列函数，根据给定的键值计算散列位置
    int hash(int key) {
        int d = 1, temp;
        temp = key % P; // 确定key该放入的地址
        if (temp < 0) { // 如果key为负数
            temp = (temp + d) % tableSize;
            d++;
        }
        return temp;
    }
    // 查找函数，根据给定的键值在散列表中查找对应的位置
    int find(int key) {
        int currentPos, newPos, d = 1;
        int cNum = 0; // 记录冲突次数
        newPos = currentPos = hash(key); // 初始散列位置
        // 当该位置的单元非空，并且不是要找的元素时，发生冲突
        while (!cells[newPos].empty && cells[newPos].data != key) {
            newPos = (currentPos + d) % tableSize; // 线性探索解决冲突
            d++;
            cNum++;
        }
        sum1 += (cNum + 1); // （每个插入元素的冲突次数+1）的总和=所有元素查找成功总次数
        return newPos; // 此时newPos或者是key的位置，或者是一个空单元的位置（表示找不到）
    }
    // 插入函数，根据给定的键值在散列表中插入一个元素
    bool insert(int key) {
        int pos = find(key); // 先检测key是否已经存在
        if (cells[pos].empty) {
            // 如果这个单元没有被占，说明key可以插入在此
            cells[pos].empty = false;
            cells[pos].data = key;
            return true;
        }
        else // 键值已经存在
            return false;
    }
    // 统计查找失败时的总查找次数
    void check_fail() {
        int i, j, count;
        for (i = 0; i < P; i++) {
            // 注意这里是从0到P，而不是从0到tableSize，也就是说只需统计散列函数能直接映射到的位置
            if (cells[i].empty)
                sum2 = sum2 + 1; // 如果查找位置为空则一次查找就可以确定查找位置为空
            if (!cells[i].empty) {
                // 如果查找位置不为空要从该元素位置开始查找到元素位置为空的位置才能确定查找失败
                count = 0;
                for (j = i; j < tableSize; j++) { // 注意这里是在tableSize长度的散列表中查找
                    count++;
                    if (cells[j].empty)
                        break;
                    if (j == tableSize - 1)
                        // 若j达到tableSize - 1，让j置0，因为j是从i开始的i前面的元素还没统计
                        j = -1; // 因为进入for循环的时候j++可以使j置0所以这里让j=-1
                }
                sum2 += count; // 统计查找次数
            }
        }
    }
};

int main() {
    int i, j;
    int key;
    unique_ptr<HashTable> H; // 使用智能指针管理散列表对象的内存
    cin >> N >> M >> P;
    H = make_unique<HashTable>(M); // 创建一个大小为M的散列表
    for (i = 0; i < N; i++) {
        cin >> key;
        H->insert(key); // 插入元素
    }
    H->check_fail(); // 统计查找失败次数
    cout << sum1 << "/" << N << endl;
    cout << sum2 << "/" << P << endl;
    return 0;
}
