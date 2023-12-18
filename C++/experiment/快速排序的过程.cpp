#include <iostream>
#include <vector>
using namespace std;
// 快速排序的Partition过程
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为基准元素
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        while (left <= right && arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);
    return right;
}

// 快速排序递归函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 进行一趟Partition
        int pivotIndex = partition(arr, low, high);

        // 输出当前趟的结果
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // 递归对基准元素左右两侧进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    return 0;
}


