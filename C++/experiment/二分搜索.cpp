#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 定义一个函数，判断一个矩阵中是否有两列相等
bool has_equal_columns(const vector<string>& matrix) {
    // 用一个无序集合来存储已经出现过的列
    unordered_set<string> columns;

    // 遍历每一列
    for (int i = 0; i < matrix[0].size(); i++) {
        // 用一个字符串来存储当前列的所有元素
        string column;
        
        // 遍历每一行
        for (int j = 0; j < matrix.size(); j++) {
            // 将当前元素加入到字符串中
            column += matrix[j][i];
        }

        // 如果当前列已经在集合中出现过，说明有两列相等，返回true
        if (!columns.insert(column).second) {
            return true;
        }
    }

    // 如果遍历完所有列都没有发现相等的列，返回false
    return false;
}

// 定义一个函数，检查在给定的行数情况下是否可以删除指定行数
bool can_delete_rows(const vector<string>& matrix, int rows_to_delete) {
    // 用一个临时矩阵来存储删除指定行数后的矩阵
    vector<string> temp(matrix.begin() + rows_to_delete, matrix.end());

    // 判断临时矩阵中是否有两列相等
    return !has_equal_columns(temp);
}

// 定义一个函数，利用二分搜索找到最大可删除行数
int binary_search_max_rows(const vector<string>& matrix) {
    int low = 0;
    int high = matrix.size();

    while (low < high) {
        int mid = low + (high - low) / 2; //找high和low中间位置

        if (can_delete_rows(matrix, mid)) { //如果能删除则将low移向中间位置
            low = mid + 1;
        } else {
            high = mid; //否则high移动到中间位置
        }
    }

    return low;
}

// 主函数
int main() {
    // 读入行数和列数
    int R, C;
    cin >> R >> C;

    // 用一个向量来存储矩阵
    vector<string> matrix;

    // 读入矩阵的每一行
    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        matrix.push_back(row);
    }

    // 利用二分搜索找到最大可删除行数
    int answer = binary_search_max_rows(matrix);

    // 输出答案
    cout << answer-1 << endl;

    // 返回0，表示程序正常结束
    return 0;
}
