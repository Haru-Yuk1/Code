#include <iostream>
#include <vector>
using namespace std;

// 辅助数组
vector<int> temp;
// 逆序对数量
int count = 0;

// 合并两个有序子数组，并统计逆序对
void merge(vector<int>& nums, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            // 如果右边的元素小于左边的元素，则左边的元素及其后面的元素都可以和右边的元素构成逆序对
            count += mid - i + 1;
        }
    }
    // 复制剩余的元素
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    // 将辅助数组中的元素复制回原数组
    for (int i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

// 归并排序
void merge_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        // 划分数组
        int mid = (left + right) / 2;
        // 对左右子数组进行排序
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        // 合并两个有序子数组
        merge(nums, left, mid, right);
    }
}

// 求一个数组的逆序对数量
int reverse_pairs(vector<int>& nums) {
    // 初始化辅助数组和计数器
    temp.resize(nums.size());
    count = 0;
    // 调用归并排序
    merge_sort(nums, 0, nums.size() - 1);
    // 返回逆序对数量
    return count;
}

int main() {
    // 测试用例
    vector<int> nums = {8, 5, 4, 2, 1};
    // 输出结果
    cout << "The number of reverse pairs is: " << reverse_pairs(nums) << endl;
    return 0;
}
