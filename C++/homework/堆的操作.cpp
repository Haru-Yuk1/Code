#include <iostream>
#include <vector>
using namespace std;

// 定义一个最小堆类
class MinHeap {
private:
    vector<int> data; // 用一个动态数组存储堆元素
    int capacity; // 堆的最大容量
    int size; // 堆的当前大小

    // 向上调整堆，使其满足最小堆性质
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2; // 父节点的索引
            if (data[i] < data[parent]) { // 如果当前节点比父节点小，交换它们
                swap(data[i], data[parent]);
                i = parent; // 更新当前节点的索引
            }
            else {
                break; // 如果当前节点不比父节点小，说明已经满足最小堆性质，退出循环
            }
        }
    }

    // 向下调整堆，使其满足最小堆性质
    void siftDown(int i) {
        while (i < size) {
            int left = 2 * i + 1; // 左孩子的索引
            int right = 2 * i + 2; // 右孩子的索引
            int min = i; // 最小值的索引，初始为当前节点
            if (left < size && data[left] < data[min]) { // 如果左孩子存在且比当前节点小，更新最小值的索引
                min = left;
            }
            if (right < size && data[right] < data[min]) { // 如果右孩子存在且比当前节点小，更新最小值的索引
                min = right;
            }
            if (min != i) { // 如果最小值不是当前节点，交换它们
                swap(data[i], data[min]);
                i = min; // 更新当前节点的索引
            }
            else {
                break; // 如果最小值是当前节点，说明已经满足最小堆性质，退出循环
            }
        }
    }

public:
    // 构造函数，初始化堆的容量和大小
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        data.reserve(capacity); // 预分配空间，避免频繁扩容
    }

    // 判断堆是否为空
    bool isEmpty() {
        return size == 0;
    }

    // 判断堆是否已满
    bool isFull() {
        return size == capacity;
    }

    // 插入一个元素到堆中，如果堆已满，返回false，否则返回true
    bool insert(int x) {
        if (isFull()) {
            return false;
        }
        data.push_back(x); // 将元素添加到数组末尾
        size++; // 增加堆的大小
        siftUp(size - 1); // 从最后一个节点开始向上调整堆
        return true;
    }

    // 删除堆顶的元素，如果堆为空，返回false，否则返回true
    bool removeMin() {
        if (isEmpty()) {
            return false;
        }
        data[0] = data[size - 1]; // 将最后一个元素覆盖堆顶元素
        data.pop_back(); // 删除最后一个元素
        size--; // 减少堆的大小
        siftDown(0); // 从根节点开始向下调整堆
        return true;
    }

    // 打印堆中的元素，用空格分隔
    void print() {
        for (int i = 0; i < size; i++) {
            if(i==size-1){
                cout<<data[i];
            }
            else{
                cout << data[i] << " ";
            }
            
        }
        cout << endl;
    }

    // 将一个数组调整为一个最小堆，参数为数组指针和数组长度
    void heapify(int* arr, int n) {
        data.clear(); // 清空原有的堆元素
        data.insert(data.end(), arr, arr + n); // 将数组元素复制到堆中
        size = n; // 更新堆的大小
        for (int i = (size - 2) / 2; i >= 0; i--) { // 从最后一个非叶子节点开始向下调整堆
            siftDown(i);
        }
    }
};

// 主函数，用于测试
int main() {
    int N, K, M; // 输入的参数
    cin >> N >> K; // 读入堆的容量和操作次数
    MinHeap heap(N); // 创建一个容量为N的最小堆
    for (int i = 0; i < K; i++) { // 循环读入K次操作
        int op; // 操作类型
        cin >> op; // 读入操作类型
        if (op == 1) { // 如果是插入操作
            int x; // 插入的元素
            cin >> x; // 读入插入的元素
            heap.insert(x); // 调用堆的插入方法
        }
        else if (op == -1) { // 如果是删除操作
            heap.removeMin(); // 调用堆的删除方法
        }
        heap.print(); // 打印堆中的元素
    }
    cin >> M; // 读入数组的长度
    int* arr = new int[M]; // 动态分配数组空间
    for (int i = 0; i < M; i++) { // 循环读入M个数组元素
        cin >> arr[i];
    }
    heap.heapify(arr, M); // 调用堆的调整方法，将数组转换为最小堆
    heap.print(); // 打印堆中的元素
    delete[] arr; // 释放数组空间
    return 0;
}
