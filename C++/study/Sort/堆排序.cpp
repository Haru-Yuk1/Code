#include <iostream>
#include <vector>
using namespace std;

// 交换两个元素的值
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 调整一个数组，使其满足堆的性质
// 参数说明：
// array -- 待调整的数组
// start -- 被调整节点的起始位置
// end -- 截至范围
// flag -- true表示创建最大堆，false表示创建最小堆
void heap_adjust(vector<int>& array, int start, int end, bool flag) {
    int parent = start; // 父节点的位置
    int child = 2 * start + 1; // 左孩子的位置
    while (child < end) {
        // 找出左右孩子中较大或较小的一个
        if (child + 1 < end && ((flag && array[child] < array[child + 1]) || (!flag && array[child] > array[child + 1]))) {
            child++;
        }
        // 比较父节点和子节点的大小，根据flag决定是否交换
        if ((flag && array[parent] < array[child]) || (!flag && array[parent] > array[child])) {
            swap(array[parent], array[child]);
            // 更新父节点和子节点的位置
            parent = child;
            child = 2 * parent + 1;
        } else {
            // 调整结束
            break;
        }
    }
}

// 堆排序
// 参数说明：
// array -- 待排序的数组
// flag -- true表示升序排序，false表示降序排序
void heap_sort(vector<int>& array, bool flag) {
    int n = array.size(); // 数组的长度
    // 初始化堆，从最后一个非叶子节点开始，自下而上，自右而左调整
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap_adjust(array, i, n, flag);
    }
    // 交换堆顶元素和最后一个元素，然后重新调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heap_adjust(array, 0, i, flag);
    }
}

int main() {
    // 测试用例
    vector<int> nums = {8, 5, 4, 2, 1};
    // 输出原始数组
    cout << "The original array is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    // 升序排序
    heap_sort(nums, true);
    // 输出升序结果
    cout << "The ascending order is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    // 降序排序
    heap_sort(nums, false);
    // 输出降序结果
    cout << "The descending order is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
