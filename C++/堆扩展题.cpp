#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 堆排序算法和C++针对几乎有序的数组进行排序
void heapSort(vector<int>& arr, int k) {
    // 创建一个大小为k+1的最小堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 将数组中的前k+1个元素加入堆中
    int index=0;
    for (; index <= k && index < arr.size(); index++) {
        minHeap.push(arr[index]);
    }
    // 创建一个结果数组
    int i=0;
    // 从第k+2个元素开始遍历数组
    for (; index < arr.size(); i++,index++) {
        //放一个数进小根堆
        minHeap.push(arr[index]);
        //弹一个数放到数组里去
        arr[i]=minHeap.top();
        minHeap.pop();
        
        
    }
    // 将堆中剩余的元素依次放入结果数组中
    while (!minHeap.empty()) {
        arr[i++]=minHeap.top();
        minHeap.pop();
    }
    
}

// 测试代码
int main() {
    // 创建一个几乎有序的数组
    vector<int> arr = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
    // 打印原数组
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    // 设置k为2
    int k = 2;
    // 调用堆排序算法和C++针对几乎有序的数组进行排序
    heapSort(arr, k);
    // 打印排序后的数组
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 下面是添加了一个结果数组res作为辅助的方法



// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// // 堆排序算法和C++针对几乎有序的数组进行排序
// void heapSort(vector<int>& arr, int k) {
//     // 创建一个大小为k+1的最小堆
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     // 将数组中的前k+1个元素加入堆中
//     for (int i = 0; i <= k && i < arr.size(); i++) {
//         minHeap.push(arr[i]);
//     }
//     // 创建一个结果数组
//     vector<int> res;
//     // 从第k+2个元素开始遍历数组
//     for (int i = k + 1; i < arr.size(); i++) {
//         // 从堆中弹出最小的元素，并将其放入结果数组中
//         res.push_back(minHeap.top());
//         minHeap.pop();
//         // 将当前元素加入堆中
//         minHeap.push(arr[i]);
//     }
//     // 将堆中剩余的元素依次放入结果数组中
//     while (!minHeap.empty()) {
//         res.push_back(minHeap.top());
//         minHeap.pop();
//     }
//     // 将结果数组复制到原数组中
//     arr = res;
// }

// // 测试代码
// int main() {
//     // 创建一个几乎有序的数组
//     vector<int> arr = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
//     // 打印原数组
//     cout << "Original array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
//     // 设置k为2
//     int k = 2;
//     // 调用堆排序算法和C++针对几乎有序的数组进行排序
//     heapSort(arr, k);
//     // 打印排序后的数组
//     cout << "Sorted array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
// }
