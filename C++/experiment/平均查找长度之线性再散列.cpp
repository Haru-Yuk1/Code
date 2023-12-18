#include <iostream>
#include <vector>
using namespace std;

// 散列函数，返回一个整数在散列表中的位置
int hash1(int x, int m, int p) {
  return x % p % m;
}

// 线性再散列，如果发生冲突就找下一个空位置
void linear_rehash(vector<int>& table, int x, int m, int p) {
  int index = hash1(x, m, p); // 计算散列位置
  while (table[index] != -1) { // 如果位置已经被占用
    index = (index + 1) % m; // 找下一个位置
  }
  table[index] = x; // 存储元素
}

// 计算查找成功时的平均查找长度
void average_search_length_success(vector<int>& table, vector<int>& keys, int m, int p) {
  int total_length = 0; // 总查找长度
  int total_count = 0; // 总查找次数
  for (int x : keys) { // 遍历所有元素
    int index = hash1(x, m, p); // 计算散列位置
    int length = 1; // 查找长度
    while (table[index] != x) { // 如果没有找到元素
      index = (index + 1) % m; // 找下一个位置
      length++; // 增加查找长度
    }
    total_length += length; // 累加总查找长度
    total_count++; // 累加总查找次数
  }
  cout<<total_length<<"/"<<total_count<<endl;
}

// 计算查找失败时的平均查找长度
void average_search_length_failure(vector<int>& table, int m, int p) {
  int total_length = 0; // 总查找长度
  int total_count = 0; // 总查找次数
  for (int i = 0; i < m; i++) { // 遍历所有位置
    if (table[i] == -1) { // 如果位置为空
      int index = i; // 计算散列位置
      int length = 1; // 查找长度
      while (table[index] != -1) { // 如果没有找到空位置
        index = (index + 1) % m; // 找下一个位置
        length++; // 增加查找长度
      }
      total_length += length; // 累加总查找长度
      total_count++; // 累加总查找次数
    }
  }
  cout<<total_length<<"/"<<total_count<<endl;
  
}

int main() {
  int n, m, p; // 输入的三个整数
  cin >> n >> m >> p; // 读取输入
  vector<int> keys(n); // 存储元素的数组
  for (int i = 0; i < n; i++) { // 读取元素
    cin >> keys[i];
  }
  vector<int> table(m, -1); // 初始化散列表，-1表示空位置
  for (int x : keys) { // 遍历所有元素
    linear_rehash(table, x, m, p); // 线性再散列
  }
  // 输出查找成功时的平均查找长度
  average_search_length_success(table, keys, m, p) ;
  // 输出查找失败时的平均查找长度
  average_search_length_failure(table, m, p) ;
  return 0;
}
