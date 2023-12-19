#include <iostream>
#include <cmath>

using namespace std;
// 判断是否为素数
bool is_prime(int n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, p;
  cin >> n >> p;

  // 检查输入
  if (n > 1000 || p < n || !is_prime(p)) {
    cout << "输入错误" << endl;
    return 0;
  }

  // 初始化散列表
  int hashTable[p];
  for (int i = 0; i < p; i++) {
    hashTable[i] = -1;
  }

  // 插入关键字
  for (int i = 0; i < n; i++) {
    int key ; 
    cin >> key;
    int index = key % p;

    // 线性探测法解决冲突
    while (hashTable[index] != -1) {
      index = (index + 1) % p;
    }

    hashTable[index] = key;
  }

  // 输出结果
  for (int i = 0; i < n; i++) {
    cout << hashTable[i] << " ";
  }
  cout << endl;

  return 0;
}

