#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 一个函数，用来输出一个排列
void print_permutation(const vector<int>& permutation) {
    for (int i = 0; i < permutation.size(); i++) {
        cout << permutation[i];
        if (i < permutation.size() - 1) {
            cout << " "; // 数字间用空格分开
        }
    }
    cout << endl; // 每个排列一行
}

// 一个函数，用来生成所有的排列
void generate_permutations(vector<int>& nums, int start, int end) {
    if (start == end) { // 如果只有一个数字，直接输出
        print_permutation(nums);
    } else {
        for (int i = start; i <= end; i++) {
            // 交换第start个和第i个数字
            swap(nums[start], nums[i]);
            // 递归地生成剩下的排列
            generate_permutations(nums, start + 1, end);
            // 恢复原来的顺序
            swap(nums[start], nums[i]);
        }
    }
}

int main() {
    int N; // 输入的整数N
    cin >> N;
    vector<int> nums(N); // 输入的N个数字
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    // 对输入的数字进行排序，保证按字典序输出
    sort(nums.begin(), nums.end());
    // 调用函数，生成所有的排列
    generate_permutations(nums, 0, N - 1);
    return 0;
}
