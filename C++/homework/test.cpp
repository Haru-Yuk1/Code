#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// 定义一个函数，判断两个字符串是否相等
bool equal(string a, string b) {
  return a == b;
}

// 定义一个函数，判断一个矩阵中是否有两列相等
bool has_equal_columns(vector<string> matrix) {
  // 用一个集合来存储已经出现过的列
  set<string> columns;
  // 遍历每一列
  for (int i = 0; i < matrix[0].size(); i++) {
    // 用一个字符串来存储当前列的所有元素
    string column = "";
    // 遍历每一行
    for (int j = 0; j < matrix.size(); j++) {
      // 将当前元素加入到字符串中
      column += matrix[j][i];
    }
    // 如果当前列已经在集合中出现过，说明有两列相等，返回true
    if (columns.count(column) > 0) {
      return true;
    }
    // 否则，将当前列加入到集合中
    columns.insert(column);
  }
  // 如果遍历完所有列都没有发现相等的列，返回false
  return false;
}

// 定义一个函数，计算可以从表格的顶部删除的最大行数
int max_rows_to_delete(vector<string> matrix) {
  // 用一个变量来存储结果
  int result = 0;
  // 从第一行开始，依次尝试删除每一行
  for (int i = 0; i < matrix.size(); i++) {
    // 用一个临时矩阵来存储删除当前行后的矩阵
    vector<string> temp;
    // 将当前行之后的所有行加入到临时矩阵中
    for (int j = i ; j < matrix.size(); j++) {
      temp.push_back(matrix[j]);
    }
    // 判断临时矩阵中是否有两列相等
    if (has_equal_columns(temp)) {
      // 如果有，说明不能删除当前行，返回结果
      return result;
    }
    // 如果没有，说明可以删除当前行，将结果加一
    result++;
  }
  // 如果遍历完所有行都没有发现不能删除的行，返回结果
  return result;
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
  // 调用函数，计算可以从表格的顶部删除的最大行数
  int answer = max_rows_to_delete(matrix);
  // 输出答案
  cout << answer-1 << endl;
  // 返回0，表示程序正常结束
  return 0;
}
