#include <iostream>
#include <vector>
using namespace std;

// 定义一个计数排序函数，参数为一个整数向量
void counting_sort(vector<int>& nums) {
    // 找出向量中的最大值和最小值
    int max_num = nums[0];
    int min_num = nums[0];
    for (int num : nums) {
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    // 创建一个计数向量，大小为最大值和最小值的差加一
    vector<int> count(max_num - min_num + 1, 0);
    // 遍历原向量，对每个元素在计数向量中对应的位置加一
    for (int num : nums) {
        count[num - min_num]++;
    }
    // 遍历计数向量，将每个元素按照出现的次数依次放回原向量
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            nums[index++] = i + min_num;
            count[i]--;
        }
    }
}

int main() {
    int n; // 输入的整数个数
    cin >> n; // 输入整数个数
    vector<int> nums(n); // 创建一个存储整数的向量
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 输入每个整数
    }
    counting_sort(nums); // 对整数进行计数排序
    for (int num : nums) {
        cout << num << " "; // 输出排序后的整数
    }
    cout << endl;
    return 0;
}
